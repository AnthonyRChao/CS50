# import necessary packages and helper functions
import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Ensure environment variable is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # Initialize stocks list
    stocks_raw = db.execute('SELECT symbol AS security, '
                        '       SUM(quantity) AS shares '
                        '  FROM trades '
                        ' WHERE user_id = :id '
                        ' GROUP BY symbol '
                        ' ORDER BY symbol ASC',
                        id=session["user_id"])

    # Initialize new list to store securities with shares > 0
    stocks = []

    # Append values from stocks_raw where shares > 0
    for i, stock in enumerate(stocks_raw):
        if (stock['shares'] > 0):
            stocks.append(stocks_raw[i])

    # Add price key to stocks list
    for stock in stocks:
        stock.update({'price':lookup(stock['security'])['price']})

    # Add value to stocks list
    for stock in stocks:
        stock.update({'value':stock['price'] * stock['shares']})

    # Query for user's cash balance
    cash = db.execute("SELECT cash FROM users WHERE id = :id",
                               id=session["user_id"])[0]['cash']
    # Calculate Grand Total
    total_stock_value = 0
    for stock in stocks:
        total_stock_value += int(stock['value'])

    total = cash + total_stock_value

    return render_template("index.html",
                            cash=usd(cash),
                            total=usd(total),
                            stocks=stocks)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":

        # Confirm user provided valid symbol
        if not request.form.get("symbol"):
            return apology("Must provide valid symbol", 400)

        # Confirm user provided valid amount for shares

        # I am getting a string value from a user input, I want to confirm if it's an integer

        while True:
            try:
                num_of_shares = int(request.form.get("shares"))
                break
            except:
                return apology("Please provide an integer.", 400)

        # # Confirm amount of shares is an int
        # if not isinstance(num_of_shares, int):
        #     return apology("Please provide an integer.", 400)

        if num_of_shares <= 0:
            return apology("Must provide positive integer", 400)

        # Get price from symbol provided by user
        data = lookup(request.form.get("symbol"))

        if (data is None):
            return apology("Please provide a valid symbol.", 400)

        price = data["price"]

        # Query database for cash
        user_cash = db.execute("SELECT cash FROM users WHERE id = :id",
                               id=session["user_id"])
        user_cash = user_cash[0]['cash']

        # Total cost of trade & remaining cash
        total_cost = price * num_of_shares
        cash_remaining = user_cash - total_cost

        # Confirm user has enough to purchase
        if user_cash > total_cost:

            # Insert a row to represent purchase and record transaction
            new_trade = db.execute("""
                                   INSERT INTO trades ('user_id','symbol','quantity','price','cost')
                                   VALUES (:id, :symbol, :quantity, :price, :cost)
                                   """,
                                   id=session["user_id"],
                                   symbol=request.form.get("symbol").upper(),
                                   quantity=num_of_shares,
                                   price=price,
                                   cost=total_cost)

            # Update users table
            update_user_table = db.execute('UPDATE users SET cash = :cash WHERE id = :id',
                                           cash=cash_remaining,
                                           id=session["user_id"])

            return render_template("bought.html",
                                    num_of_shares=num_of_shares,
                                    symbol=request.form.get("symbol").upper(),
                                    price=usd(price),
                                    total_cost=usd(total_cost),
                                    cash_remaining=usd(cash_remaining))
        else:
            return apology("Insufficient funds", 400)
    else:
        return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Display an HTML table summarizing all of users trades
    # Show type of transaction (buy or sell), symbol, price, quantity bought/sold, and timestamp

    # Initialize trades list
    trades_raw = db.execute('SELECT CASE '
                            '       WHEN quantity > 0 THEN "BUY" '
                            '       ELSE "SELL" '
                            '       END AS action, '
                            '       symbol AS security, '
                            '       price, '
                            '       quantity, '
                            '       timestamp '
                            '  FROM trades '
                            ' WHERE user_id = :id '
                            ' ORDER BY timestamp ASC',
                            id=session["user_id"])

    return render_template("history.html", trades_raw=trades_raw)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

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

    # (DONE) Require user input stock symbol as a text field whose name is symbol

    # Submit user's input via POST to /quote
    if request.method == "POST":

        data = lookup(request.form.get("symbol"))
        if (data is None):
            return apology("Please provide a valid symbol.", 400)

        price = usd(data["price"])
        return render_template("quoted.html", data=data, price=price)

    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure confirmation was submitted
        elif not request.form.get("confirmation"):
            return apology("must provide confirmation", 400)

        # Ensure password matches confirmation
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password and confirmation must match", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username does not already exist
        if len(rows) == 1:
            return apology("username already exists", 400)
        else:
            # Insert new user and hashed password into users table
            db.execute('INSERT INTO "users" ("id", "username", "hash") VALUES (NULL, :username, :password)',
                        username=request.form.get("username"),
                        password=generate_password_hash(request.form.get("password")))

        # Redirect user to home page
        return redirect("/")

    return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":

        # Call lookup() on user's symbol input, returns an object with name, symbol, and price
        symbol_obj = lookup(request.form.get("symbol"))

        # Check if user owns shares
        if (symbol_obj is None):
            return apology("No shares owned.", 400)

        # Price from symbol_obj
        price = symbol_obj["price"]

        # Symbol from symbol_obj
        symbol = symbol_obj["symbol"]

        # User quantity input * (-1)
        shares_to_sell = int(request.form.get("shares"))

        # Cash value of sale
        cash_from_sale = price * shares_to_sell

        # User's current cash balance
        current_cash = db.execute("SELECT cash FROM users WHERE id = :id",
                                   id=session["user_id"])[0]['cash']

        # User's available shares to sell
        shares_avail = db.execute('SELECT SUM(quantity) AS shares '
                                  'FROM trades '
                                  'WHERE user_id = :id '
                                  'AND symbol = :symbol ',
                                  id=session["user_id"],
                                  symbol=symbol)[0]["shares"]

        # User's new cash balance
        updated_cash = current_cash + cash_from_sale

        # Make sure user has the shares
        if (shares_to_sell > shares_avail):
            return apology("Not enough shares to sell.", 400)

        # Make sure shares to sell is a positive integer
        elif (shares_to_sell < 1):
            return apology("Shares must be greater than 0.", 400)

        else:
            # INSERT record into trades table to record trade
            db.execute('INSERT INTO trades (user_id, symbol, quantity, price, cost) '
                      'VALUES (:id, :symbol, :quantity, :price, :cost) ',
                      id=session["user_id"],
                      symbol=symbol,
                      quantity=shares_to_sell*(-1),
                      price=price,
                      cost=cash_from_sale)

            # UPDATE user's cash in user table
            db.execute('UPDATE users '
                      'SET cash = :updated_cash '
                      'WHERE id = :id',
                      id=session["user_id"],
                      updated_cash=updated_cash)

        return render_template("sold.html",
                               symbol=symbol,
                               shares_to_sell=shares_to_sell,
                               price=usd(price),
                               cash_from_sale=usd(cash_from_sale),
                               current_cash=usd(current_cash),
                               shares_avail=shares_avail,
                               updated_cash=usd(updated_cash))

    # User's available symbols
    stocks_raw = db.execute('SELECT symbol, '
                        '       SUM(quantity) AS quantity '
                        'FROM trades '
                        'WHERE user_id = :id '
                        'GROUP BY symbol ',
                        id=session["user_id"])

    # Initialize new list to store securities with shares > 0
    stocks = []

    # Append values from stocks_raw where shares > 0
    for i, stock in enumerate(stocks_raw):
        if (stock['quantity'] > 0):
            stocks.append(stocks_raw[i])

    return render_template("sell.html", stocks=stocks)

@app.route("/add_funds", methods=["GET", "POST"])
@login_required
def add_funds():
    """Add funds to account."""

    # Submit user's input via POST to /add_funds
    if request.method == "POST":

        old = db.execute("SELECT cash FROM users WHERE id = :id",
                           id=session["user_id"])[0]['cash']

        add = float(request.form.get("amount"))

        # Make sure user entered a positive number
        if add < 0:
            return apology("Please enter a positive number.", 400)

        new = old + add

        # UPDATE user's cash in user table
        db.execute('UPDATE users '
                  'SET cash = :new '
                  'WHERE id = :id',
                  id=session["user_id"],
                  new=new)

        return render_template("added_funds.html",
                               old=usd(old),
                               add=usd(add),
                               new=usd(new))

    return render_template("add_funds.html")

def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
