// assume: string will be only letters and spaces & only single space between names

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
        // print the first char as upper case
        printf("%c", toupper(s[0]));

        // iterate through the string
        for (int i = 1, n = strlen(s); i < n; i++)
        {
            // if the current char is a space, print the next char in upper case
            if (s[i] == ' ')
            {
                printf("%c", toupper(s[i+1]));
            }
        }
        printf("\n");
    }
}