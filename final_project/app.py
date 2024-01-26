
from flask import Flask, render_template, session, request, redirect, url_for
from flask_session import Session
from cs50 import SQL
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import login_required
from datetime import datetime

# Configure application
app = Flask(__name__)
# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///users.db")

# Index.html homepage
@app.route("/")
def index():

    logged_in = "user_id" in session
    if logged_in:

        # Get username of logged user
        result = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])
        username = result[0]['username']
    else:
        username = None

    # Get all posts from the database
    posts = db.execute("SELECT * FROM posts")

    # If index.html request is GET
    return render_template("index.html", message="", logged_in=logged_in, username=username, posts=posts)

# Register.html
@app.route("/register", methods=["GET", "POST"])
def register():       
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # In any field is empty, render message
        if not username or not password or not confirmation:    
            return render_template("register.html", message="Username and password can't be empty.")

        # Check if password is same as pass confirmation
        if password != confirmation:
            return render_template("register.html", message="Password and confirm password are not the same. Try again.")

        # Check if user is already in database
        existing_user = db.execute("SELECT id FROM users WHERE username = ?", username)
        if existing_user:
            return render_template("register.html", message="Username is taken.")
        else:
            hashed_password = generate_password_hash(password, method='pbkdf2', salt_length=16)
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hashed_password)
            return render_template("login.html", message="Successful registration! You can login now.")        

    # If register reguest is GET
    return render_template("register.html")

# Login.html
@app.route("/login", methods=["GET", "POST"])
def login():

    # Clear session data to prevent session conflicts
    session.clear()

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        # Check if username and password is submitted
        if not username or not password:
            return render_template("login.html", message="Username and password cant be empty.")

        # Check if username is in database
        user = db.execute("SELECT * FROM users WHERE username = ?", username)
        
        # Check for multiple rows in db for username, and if password_hash match password
        if len(user) != 1 or not check_password_hash(user[0]["hash"], password):
            return render_template("login.html", message="Invalid username or password.")
        
        # Remember which user has logged in
        session["user_id"] = user[0]["id"]

        # Handle logged_in defined in index.html for different menu options
        logged_in = "user_id" in session

        # Get username of logged user
        result = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])
        username = result[0]['username']

        # Redirect logged user to homepage
        # return render_template("index.html", message="You are logged in.", logged_in=logged_in, username=username)
        return redirect(url_for("index"))

    # If login request is GET 
    return render_template("login.html")

# Logout.html
@app.route("/logout")
def logout():

    # Clear session data
    session.clear()

    # Redirect user to login form
    return render_template("login.html", message="You have logged out.")

# Create post.html
@app.route("/post", methods=["GET", "POST"])
@login_required
def post():

    logged_in = "user_id" in session

    # Get username of logged user
    result = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])
    username = result[0]['username']

    if request.method == "POST":
        current_user = session.get('user_id')
        title = request.form.get("title")
        post = request.form.get("post")
        current_datetime = datetime.now()

        db.execute("INSERT INTO posts (user_id, title, post, time) VALUES (?, ?, ?, ?)",
                    current_user, title, post, current_datetime)
        
        return render_template("post.html", message="Post published successfuly.", username=username, logged_in=logged_in)

    return render_template("post.html", username=username, logged_in=logged_in)

# Delete post
@app.route("/delete/<int:post_id>", methods=["POST"])
def delete(post_id):

    #logged_in = "user_id" in session

    # Get username of logged user
    #result = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])
    #username = result[0]['username']

    if request.method == "POST":
        # Delete the post with the given post_id from the database
        db.execute("DELETE FROM posts WHERE id = ?", post_id)
        return redirect(url_for("index"))
        # return render_template("index.html", message="Post deleted.", username=username, logged_in=logged_in)