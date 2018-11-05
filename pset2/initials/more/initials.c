// assume: string will be only letters and spaces, could have multiple spaces
// 'A's ASCII code is 65, 'z's ASCII code is 122, ' 's ASCII code is 32

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // get input string from user
    string s = get_string();

    if (s != NULL)
    {
        // iterate through the string (array of chars)
        for (int i = 0, n = strlen(s); i < n; i++)
        {

            // if first char is in alphabet, print char as upper case
            if (s[0] >= 'A' && s[0] <= 'z' && i == 0)
            {
                printf("%c", toupper(s[0]));
            }

            // if char is part of alphabet & previous char is a space, then print char to upper case
            if (s[i] >= 'A' && s[i] <= 'z' && s[i-1] == ' ')
            {
                printf("%c", toupper(s[i]));
            }
        }
        printf("\n");
    }
}