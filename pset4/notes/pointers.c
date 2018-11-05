#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = get_string();
    if (s == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        /**
         * s is the address of a string
         * add i to s
         * *s means go to s, what do you find, you find a char
         * go print that char right there
         * s+1 is one byte farther, go print that next char
         * etc.
         * This is pointer arithemtic, math with pointers
         */

        // printf("%c\n", *(s+i));
        printf("%c\n", s[i]);
    }
}