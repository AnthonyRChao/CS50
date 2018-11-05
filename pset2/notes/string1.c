#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // ask user for input
    string s = get_string();

    // make sure get_string returns a string
    if (s != NULL)
    {
        // iterate over characters in s one at a time
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // print i-th character in s
            printf("%c\n", s[i]);
        }
    }
}