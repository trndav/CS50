from flask import Flask, redirect, render_template, request, session
from flask_session import Session

# Configure app
app = Flask(__name__)

# Configure session
app.config["SESSION_PERMANENT"] = False # Cookie deleted on browser close
app.config["SESSION_TYPE"] = "filesystem" # Content on session is stored on server and not in cookie
Session(app)

@app.route("/")
def index():
    return render_template("139index.html", name=session.get("name"))

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("141login.html")

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")