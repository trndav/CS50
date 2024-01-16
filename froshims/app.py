from flask import Flask, redirect, render_template, request
app = Flask(__name__)
REGISTRANTS = {}
SPORTS = [ "Basketball", "Soccer", "Ultimate Frisbee" ]

@app.route("/")
def index():
    return render_template("130index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():

    # Validate name
    name = request.form.get("name")
    if not name:
        return render_template("132failure.html", message="Missing name")

    # Validate sport
    sport = request.form.get("sport")
    if not sport:
        return render_template("132failure.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("132failure.html", message="Invalid sport")

    # Remember registrant
    REGISTRANTS[name] = sport

    # Confirm registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)