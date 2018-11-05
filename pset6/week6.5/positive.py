from cs50 import get_int

def main():
    i = get_positive_int("please enter a positive integer: ")
    print(i)

def get_positive_int(prompt):
    while True:
        n = get_int(prompt)
        if n >= 1:
            break
    return n

if __name__ == "__main__":
    main()