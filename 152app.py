import os
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, make_response, url_for
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required, lookup, usd
from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if 'user_id' in session:
        current_user = session.get('user_id')
        symbol = request.form.get("symbol")

        # Symbol
        db_symbol = db.execute("SELECT share_name FROM shares WHERE user_id = ?", current_user)
        if db_symbol:
            db_symbol_name = db_symbol[0]['share_name']
        else:
            db_symbol_name = None

        #Shares
        count_shares = db.execute("SELECT SUM(shares) FROM shares WHERE user_id = ?", current_user)
        count_shares_number = count_shares[0]['SUM(shares)']

        #Price
        if db_symbol_name is not None:
            symbol_value = lookup(db_symbol_name)
        else:
            symbol_value = None

        #Shares value
        if symbol_value is not None:
            total_shares_value = float(symbol_value["price"]) * count_shares_number
        else:
            total_shares_value = 0

        #Cash (changed for:
        cash = db.execute("SELECT cash FROM users WHERE id = ?", current_user)
        count_number = cash[0]['cash']
        formatted_cash = format(count_number, ".2f")

        # Test
        # Test count shares
        shares_data = db.execute("SELECT share_name, CAST(shares AS FLOAT) AS shares_float, share_price AS share_price FROM shares WHERE user_id = ? GROUP BY share_name", current_user)

        rows = db.execute("SELECT * FROM shares WHERE user_id = ?", session["user_id"])
        symbol_shares = {}

        for row in shares_data:
            symbol = row["share_name"]


            current_symbol_value = lookup(symbol)
            current_symbol_value_float = float(current_symbol_value["price"])


            shares = row["shares_float"]

            if symbol in symbol_shares:
                symbol_shares[symbol]["count_shares_number"] += shares
            else:
                test_count_shares = db.execute("SELECT SUM(shares) AS total_shares FROM shares WHERE user_id = ? AND share_name = ?", current_user, symbol)
                count_shares_number = test_count_shares[0]['total_shares']
                total_shares_value = count_shares_number * float(row["share_price"])
                total_shares_value_formated = format(total_shares_value, ".2f")
                symbol_shares[symbol] = {
                "db_symbol_name": symbol,
                "count_shares_number": count_shares_number,

                "symbol_value": current_symbol_value_float,

                "total_shares_value": total_shares_value_formated,
                }

        data_list = list(symbol_shares.values())

        total_shares_values = [float(data["total_shares_value"]) for data in data_list]
        total_shares_value_sum = sum(total_shares_values)

        # Total
        total = count_number + total_shares_value_sum
        formatted_total = format(total, ".2f")

        return render_template("index.html", data_list=data_list, count_number=formatted_cash, total=formatted_total)

    return render_template("login.html")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    symbol = request.form.get("symbol")
    shares = request.form.get("shares")
    current_user = session.get('user_id')
    user_cash_query = db.execute("SELECT cash FROM users WHERE id = ?", current_user)
    user_cash = user_cash_query[0]['cash']

    if request.method == "POST":
        try:
            int_shares = int(shares)
            if int_shares < 0:
                apology_message = "Shares cant be less than 0."
                response = make_response(render_template("apology.html", message=apology_message), 400)
                return response
        except ValueError:
            apology_message = "Invalid input for shares. Please enter a valid number."
            response = make_response(render_template("apology.html", message=apology_message), 400)
            return response


        if not symbol or not shares:
            return apology("Quote and shares cant be empty.")
        result = lookup(symbol)
        if result is None:
            return apology("Quote does not exist.")

        # Check if user has enough cash
        price=result["price"]
        formatted_price = app.jinja_env.filters['usd'](result["price"])
        total_price = float(price) * float(shares)
        if total_price > user_cash:
            return apology("Not enough cash")

        current_datetime = datetime.now()
        new_cash = float(user_cash) - float(total_price)

        # Check if a row with the specified user_id already exists
        existing_row = db.execute("SELECT * FROM shares WHERE user_id = ? AND share_name = ?", current_user, symbol)
        if not existing_row:
            # INSERT data to shares table
            db.execute("INSERT INTO shares (user_id, shares, share_name, share_price, time) VALUES (?, ?, ?, ?, ?)",
                    current_user, shares, symbol, price, current_datetime)
        else:
            # Test history
            db.execute("INSERT INTO shares (user_id, shares, share_name, share_price, time) VALUES (?, ?, ?, ?, ?)",
            current_user, shares, symbol, price, current_datetime)

        # Update data in users table
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, current_user)

        #return render_template("index.html", message=f"Bought for {formatted_price}!")
        return redirect(url_for('index', message="Bought"))

    #return render_template("buy.html", current_user=session.get('user_id'), user_cash=user_cash)
    return render_template("buy.html")
    # return apology("TODO")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    if 'user_id' in session:
        current_user = session.get('user_id')
        transactions = db.execute("SELECT share_name, shares, share_price, time FROM shares WHERE user_id = ?", current_user)

        return render_template("/history.html", transactions=transactions)

    #return apology("TODO")

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if symbol is None or not symbol.strip():
            apology_message = "Quote cant be empty."
            response = make_response(render_template("apology.html", message=apology_message), 400)
            return response
            #return render_template("quote.html", message="Quote cant be empty.")

        result = lookup(symbol)
        if result is None:
            return apology("Quote does not exist.")

        formatted_price = app.jinja_env.filters['usd'](result["price"])
        return render_template("quoted.html", name=result["symbol"], price=formatted_price)

    return render_template("quote.html")

    # return apology("TODO")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    username = request.form.get("username")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    if request.method == "POST":
        if username is None or password is None or confirmation is None:
            apology_message = "Username and password can't be empty."
            response = make_response(render_template("apology.html", message=apology_message), 400)
            return response

        if not username or not password or not confirmation:
            apology_message = "Username and password can't be empty."
            response = make_response(render_template("apology.html", message=apology_message), 400)
            return response

        if password != confirmation:
            apology_message = "Passwords do not match."
            response = make_response(render_template("apology.html", message=apology_message), 400)
            return response

        # Check if user is already in db
        existing_user = db.execute("SELECT id FROM users WHERE username = ?", username)
        if existing_user:
            apology_message = "Username is taken."
            response = make_response(render_template("apology.html", message=apology_message), 400)
            return response
        else:
            hashed_password = generate_password_hash(password, method='pbkdf2', salt_length=16)
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hashed_password)

        return redirect('/')
    else:
        return render_template("/register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if 'user_id' in session:
        if request.method == "POST":
            current_user = session.get('user_id')
            symbol = request.form.get("symbol")
            shares = request.form.get("shares")
            user_cash_query = db.execute("SELECT cash FROM users WHERE id = ?", current_user)
            user_cash = user_cash_query[0]['cash']
            result = lookup(symbol)

            try:
                int_shares = int(shares)
                if int_shares < 0:
                    apology_message = "Shares cant be less than 0."
                    response = make_response(render_template("apology.html", message=apology_message), 400)
                    return response
            except ValueError:
                apology_message = "Invalid input for shares. Please enter a valid number."
                response = make_response(render_template("apology.html", message=apology_message), 400)
                return response

            if not symbol or not shares:
                return apology("Quote and shares cant be empty.")

            if result is None:
                return apology("Quote does not exist.")

            price = result["price"]
            total_price = float(price) * float(shares)
            negative_shares = -int(shares)
            current_datetime = datetime.now()
            new_cash = float(user_cash) + float(total_price)

            # If shares are bigger than bought shares
            count_bought_shares_result = db.execute("SELECT sum(shares) FROM shares WHERE user_id = ? AND share_name = ?", current_user, symbol)
            count_bought_shares = count_bought_shares_result[0]["sum(shares)"] if count_bought_shares_result and count_bought_shares_result[0] else 0
            if int(count_bought_shares) < int(shares):
                #return render_template("/sell.html", message="You do not have that amount of shares")
                apology_message = "Invalid number of shares."
                response = make_response(render_template("apology.html", message=apology_message), 400)
                return response

            # Test history
            db.execute("INSERT INTO shares (user_id, shares, share_name, share_price, time) VALUES (?, ?, ?, ?, ?)",
                    current_user, negative_shares, symbol, price, current_datetime)

            # Update cash data in users table
            db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, current_user)

            return redirect(url_for('index', message="Sold!"))

    return render_template("/sell.html")
    #return apology("TODO")

@app.route("/add_cash", methods=["POST"])
@login_required
def add_cash():
    if 'user_id' in session:
        current_user = session.get('user_id')
        db_cash = db.execute("SELECT cash FROM users WHERE id = :id", id=current_user)[0]['cash']
        new_cash = float(db_cash) + 5000
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, current_user)
        return redirect("/")
