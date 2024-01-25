# Searches for shows using Ajax
from cs50 import SQL
from flask import Flask, render_template, request
app = Flask(__name__)
db = SQL("sqlite:///C:/ctest/Harvard/shows/shows.db")
@app.route("/")
def index():
    return render_template("148index.html")
@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? ORDER BY year LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return render_template("149search.html", shows=shows)