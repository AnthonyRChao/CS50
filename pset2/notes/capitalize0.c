#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // get input from user
    string s = get_string();

    // make sure s isn't null
    if (s != NULL)
    {
        // iterate through each character of s
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // confirm value is in the alphabet
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                // print upper case letters
                printf("%c", s[i] - 32);
            }
            else
            {
                // print lower case letters
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}