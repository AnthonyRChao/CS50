// program should encrypt messages w/ Ceasar's cipher

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // confirm user's input is non-negative integer
    if (argv[1] < 0)
    {
        printf("Please provide a non-negative integer argument.\n");
        return 1;
    }
    // confirm user provided one command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

    // convert string to an int
    int k = atoi(argv[1]);

    // get input from user
    printf("plaintext: ");
    string s = get_string();

    // iterate over the string and rotate each character k times
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if upper case, subtract 65, add k, sum % 26, add 65
        if (isupper(s[i]))
        {
            s[i] = (((s[i] - 65) + k) % 26) + 65;

            // s[i] -= 65; convert from ASCII to "alphabet" index
            // s[i] += k; rotate character by k
            // s[i] %= 26; wrap around
            // s[i] += 65; convert from "alphabet" index back to ASCII
        }

        // if lower case, subtract 97, add k, sum % 26, add 97
        if (islower(s[i]))
        {
            s[i] = (((s[i] - 97) + k) % 26) + 97;
        }

    }

    // print encrypted version of user input
    printf("ciphertext: %s\n", s);
    return 0;
}
