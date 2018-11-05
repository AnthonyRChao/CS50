// assume each pw is no longer than four chars
// assume that each pw is composed entirely of alphabetical chars (upper and/or lowercase)
// assume each pw has been hashed with C's DES-based crypt function

//nested loop not dynamic, 4 to 10, not scalable


#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // confirm user provided one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./crack k\n");
        return 1;
    }

    // declare dictionary to iterate over for key
    // string dict = "aA";

    // declare key array & salt array
    char key[5];
    char salt[3] = { '5', '0' };
    string cuniv = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len_cuniv = 52;
    int maxTry = 99999;


    // gio's version of the code using breadth first search instead of depth first search
    // try maxTry times
    for (int i=1; i<maxTry; i++){
        //initialize key
        for (int j=0; j<5;j++)
        {
            key[j]='\0';}

        int idx = 0;
        int k = i;

        while( k > 0 && k % len_cuniv != 0){

            key[idx++] = cuniv[k % len_cuniv - 1];

            // first line try up to Zed, then try empty string, when ke =
            k = k / len_cuniv;
        }
        if ( k == 0 ) {

            printf("i: %d, key: %s, crypt(): %s\n", i, key, crypt(key, salt));

            if (strcmp(crypt(key,salt), argv[1]) == 0)
            {
                printf("Match found. Key: %s\n", key);
                return 0;
            }
        }
    }

    // // loop 1 "_"
    // for (int counter1 = 0, len1 = strlen(dict); counter1 < len1; counter1++)
    // {
    //     key[0] = dict[counter1];
    //     printf("key: %c, crypt(): %s\n", dict[counter1], crypt(key, salt));

    //     // string compare crypt output with user provided hashed password
    //     if (strcmp(crypt(key,salt), argv[1]) == 0)
    //     {
    //         printf("Match found. Key: %s\n", key);
    //         return 0;
    //     }

    //     // loop 2"_ _"
    //     for (int counter2 = 0, len2 = strlen(dict); counter2 < len2; counter2++)
    // {
    //         key[1] = dict[counter2];
    //         printf("key: %s, crypt(): %s\n", key, crypt(key, salt));

    //         if (strcmp(crypt(key,salt), argv[1]) == 0)
    //         {
    //             printf("Match found. Key: %s\n", key);
    //             return 0;
    //         }

    //         // loop 3 "_ _ _"
    //         for (int counter3 = 0, len3 = strlen(dict); counter3 < len3; counter3++)
    //         {
    //             key[2] = dict[counter3];
    //             printf("key: %s, crypt(): %s\n", key, crypt(key, salt));

    //             if (strcmp(crypt(key,salt), argv[1]) == 0)
    //             {
    //                 printf("Match found. Key: %s\n", key);
    //                 return 0;
    //             }

    //             // loop 4 "_ _ _ _"
    //             for (int counter4 = 0, len4 = strlen(dict); counter4 < len4; counter4++)
    //             {
    //                 key[3] = dict[counter4];
    //                 printf("key: %s, crypt(): %s\n", key, crypt(key, salt));

    //                 if (strcmp(crypt(key,salt), argv[1]) == 0)
    //                 {
    //                     printf("Match found. Key: %s\n", key);
    //                     return 0;
    //                 }
    //             }
    //         }
    //     }
    // }

    printf("No match found.\n");
    return 1;
}

/*
username:hash
andi:50.jPgLzVirkc | key: hi, crypt(): 50.jPgLzVirkc
jason:50YHuxoCN9Jkc | key: JH, crypt(): 50YHuxoCN9Jkc
malan:50QvlJWn2qJGE
mzlatkova:50CPlMDLT06yY
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