# Program encrypts messages w/ Caesar's cipher

import sys
import cs50

def main():
    if len(sys.argv) != 2:
        print("Usage: python caesar.py k")

    key = int(sys.argv[1])
    encrypted = []
    plaintext = cs50.get_string("plaintext: ")

    for i in plaintext:
        if i.isalpha():
            encrypted.append(caesar(i, key))
        else:
            encrypted.append(i)

    print("ciphertext: ", "".join(encrypted))
    exit(0)

def caesar(char, key):
    if char.isupper():
        return chr(((ord(char) - 65 + key) % 26) + 65)
    else:
        return chr(((ord(char) - 97 + key) % 26) + 97)

if __name__ == "__main__":
    main()