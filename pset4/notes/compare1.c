/**
 * Why can't you just compare "s" against "t".
 * Why use strcmp()?
 * What are char *s & char *t?
 * They are addresses that point to the
 * first character of a string
 * The terminator signifies the end of a string
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("s: ");
    char *s = get_string();

    printf("t: ");
    char *t = get_string();

    if (s != NULL && t != NULL)
    {
        // strcmp takes two inputs, both the addresses of characters in memory

        if (strcmp(s, t ) == 0)
        {
            printf("same\n");
        }
        else
        {
            printf("different\n");
        }
    }
}