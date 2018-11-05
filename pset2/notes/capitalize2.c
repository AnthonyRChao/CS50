#include <cs50.h>
#include <ctype.h>
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
            // convert char to uppercase
            printf("%c", toupper(s[i]));
        }
        printf("\n");
    }
}n