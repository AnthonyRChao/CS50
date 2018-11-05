from cs50 import get_int

while True:
    print("Please input positive integer: ")
    n = get_int()
    if n > 0:
        break

# print out this many rows
for i in range(n):

    # print out this many columns
    for j in range(n):
        print("#", end = "")
    print()
