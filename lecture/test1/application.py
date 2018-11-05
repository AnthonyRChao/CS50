from flask import Flask, render_template

# Hey Flask, give me a web server
app = Flask(__name__)

# routes
@app.route("/")
def index():
    return render_template("index.html")

@app.route("/zuck")
def zuck():
    return render_template("zuck.html")

@app.route("/login")
def login():
    return render_template("login.html")