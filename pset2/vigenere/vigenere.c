// program should encrypt messages w/ Vigenere's cipher

#include <cs50.h> // get_string()
#include <stdio.h>
#include <string.h> // strlen()
#include <ctype.h> // isalpha(), isupper(), islower()

int main(int argc, string argv[])
{
    // confirm user provided only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }

    // confirm user's command line argument only contains alphabetical characters
    string k = argv[1];
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    // get plaintext input from user
    printf("plaintext: ");
    string s = get_string();

    // loop over the plaintext string by char
    for (int j = 0, f = 0, n = strlen(s); j < n; j++)
    {
        // initialize len as length of string k
        int len = strlen(k);

        // if block for lower case char, s[j]
        if (islower(s[j]))
        {
            // convert ASCII code to alphabetical index
            s[j] -= 97;
            // convert char in k to lowercase, then ASCII code to alphabetical index
            char p = tolower(k[f % len]) - 97;
            // increment s[j] by p, use % to wraparound alphabetical index
            s[j] = (s[j] + p) % 26;
            // convert from alphabetical index back to ACII code
            s[j] += 97;
            // increment key index
            f++;
        }

        // if block for upper case char, s[j]
        if (isupper(s[j]))
        {
            // convert ASCII code to alphabetical index
            s[j] -= 65;
            // convert char in k to lowercase, then ASCII code to alphabetical index
            char q = toupper(k[f % len]) - 65;
            // increment s[j] by p, use % to wraparound alphabetical index
            s[j] = (s[j] + q) % 26;
            // convert from alphabetical index back to ACII code
            s[j] += 65;
            // increment key index
            f++;
        }
    }

    // print encrypted version of user input
    printf("ciphertext: %s\n", s);
    return 0;
}