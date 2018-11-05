from cs50 import get_int

# user input
print("Height: ", end='')
max_height = get_int()

# data validation
while (max_height < 0 or max_height > 23):
    print("Height: ", end='')
    max_height = get_int()

# outer loop determines number of levels
for i in range(0, max_height):

    # inner loop #1 print out spaces
    for j in range(max_height - 1 - i, 0, -1):
        print(" ", end='')

    # inner loop #2 print out hashtags
    for k in range(0, i + 1):
        print("#", end='')

    # print out two spaces
    print("  ", end='')

    # inner loop #3 print out hashtags
    for i in range(0, i + 1):
        print("#", end='')

    # new line
    print('')