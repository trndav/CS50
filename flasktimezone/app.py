from flask import Flask 
from datetime import datetime 
from pytz import timezone

app = Flask(__name__)

@app.route("/")
def time():
    now = datetime.now(timezone('America/New_york'))
    return "The current date and time in Cambridge is {}".format(now)