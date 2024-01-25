# Searches for shows using LIKE
from cs50 import SQL
from flask import Flask, render_template, request
app = Flask(__name__)
db = SQL("sqlite:///C:/ctest/Harvard/shows/shows.db")
@app.route("/")
def index():
    return render_template("145index.html")
@app.route("/search")
def search():
    # shows = db.execute("SELECT * FROM shows WHERE title LIKE ?", request.args.get("q"))
    # To get results with more wild characters %, any characters before and after
    shows = db.execute("SELECT * FROM shows WHERE title LIKE ?", "%" + request.args.get("q") + "%")
    return render_template("146search.html", shows=shows)