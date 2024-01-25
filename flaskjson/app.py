# Searches for shows using Ajax
from cs50 import SQL
from flask import Flask, jsonify, render_template, request
app = Flask(__name__)
db = SQL("sqlite:///C:/ctest/Harvard/shows/shows.db")
@app.route("/")
def index():
    return render_template("150index.html")
@app.route("/search")
def search():
    q = request.args.get("q")
    if q:
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? ORDER BY year LIMIT 50", "%" + q + "%")
    else:
        shows = []
    return jsonify(shows)