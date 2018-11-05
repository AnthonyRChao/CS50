'''
This program is an implemention of Luhn's Algorithm.
'''

# prompt for user input
number = int(input("Number: "))

# variables to allow for manipulations of user input
temp_num_one = number
temp_num_two = number

# variables for the set of digits we will mutilply by two or sum as is
sum_one = 0
sum_two = 0

# remove right most digit and sum first set of digits
temp_num_one //= 10

while (temp_num_one):

    digit_times_two = (temp_num_one % 10) * 2

    # sum digits where digit_times_two greater than 10
    while (digit_times_two):
        remainder = digit_times_two % 10
        sum_one += remainder
        digit_times_two //= 10

    temp_num_one //= 100

# sum second set of digits
while (temp_num_two):

    digit = (temp_num_two % 10)
    sum_two += digit
    temp_num_two //= 100

# validate checksum
# validate company's identifier
# validate number's length
number_length = len(str(number))
number_first_digit = int(str(number)[:1])
number_first_two_digits = int(str(number)[:2])

sum_total = sum_one + sum_two

if (sum_total % 10 == 0):
    if (number_length == 15 and (number_first_two_digits == 34 or number_first_two_digits == 37)):
        print("AMEX")
    elif (number_length == 16 and (number_first_two_digits == 51 or number_first_two_digits == 52 or number_first_two_digits == 53 or number_first_two_digits == 54 or number_first_two_digits == 55)):
        print("MASTERCARD")
    elif (number_first_digit == 4 and (number_length == 13 or number_length == 16)):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")