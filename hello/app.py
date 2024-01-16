from flask import Flask, render_template, request
app = Flask(__name__) # Refer to file name as self
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
         name = request.form.get("name", "world")
         return render_template("127greet.html", name=name)
    return render_template("126index.html")
# + In 126index.html :  <form action="/" method="post"> (instead of "/greet")

# Or
# @app.route("/greet", methods=["POST"]) #Can be ["GET", "POST"]
# def greet():    
#     return render_template("127greet.html", name = request.form.get("name", "world"))