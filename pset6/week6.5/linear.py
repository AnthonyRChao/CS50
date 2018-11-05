from cs50 import get_string
book = [
    "A",
    "B",
    "C"]

c = get_string("Name: ")
if c in book:
    print(f"Calling, {c}")