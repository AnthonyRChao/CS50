// assume each pw is no longer than four chars
// assume that each pw is composed entirely of alphabetical chars (upper and/or lowercase)
// assume each pw has been hashed with C's DES-based crypt function
// gio's version of the code using breadth first search instead of depth first search

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{

    // confirm user provided one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./crack k\n");
        return 1;
    }

    // initilaize arrays: key, salt, cuinv
    // initialize ints: dict_length, maxTry
    char key[5] = { '\0', '\0', '\0', '\0', '\0' };
    char salt[3] = { '5', '0', '\0' };

    string dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int dict_length = strlen(dict) + 1; // plus one here to hold a position for the null terminator

    printf("dict: %s\n", dict);
    printf("dict_length: %i\n", dict_length);

    int maxTry = 9999999;

    // loop "maxTry" times
    for (int i = 1; i < maxTry; i++)
    {
        int idx = 0;
        int k = i;

        while ( k > 0 && k % dict_length != 0)
        {
            int mod_result = k % dict_length;
            key[idx++] = dict[mod_result - 1];
            k = k / dict_length;

            if (strcmp(crypt(key,salt), argv[1]) == 0)
            {
                printf("Match found. key: %s, crypt(): %s\n", key, crypt(key, salt));
                return 0;
            }
        }

        if ( k == 0)
        {
            printf("i: %d, k: %d, key: %s, crypt(): %s\n", i, k, key, crypt(key, salt));
        }
    }

    printf("No match found.\n");
    return 1;
}

/*
username:hash
andi:50.jPgLzVirkc | key: hi, crypt(): 50.jPgLzVirkc
jason:50YHuxoCN9Jkc | key: JH, crypt(): 50YHuxoCN9Jkc
malan:50QvlJWn2qJGE
mzlatkova:50CPlMDLT06yY | key: ha, crypt(): 50CPlMDLT06yY
patrick:50WUNAFdX/yjA
rbowden:50fkUxYHbnXGw
summer:50C6B0oz0HWzo
stelios:50nq4RV/NVU0I
wmartin:50vtwu4ujL.Dk
zamyla:50i2t3sOSAZtk

_ @
_ _ @
_ _ _ @
_ _ _ _ @

*/