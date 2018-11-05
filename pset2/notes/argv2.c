#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // iterate over strings in argv
    for (int i = 0; i < argc; i++)
    {
        // iterate over characters in current string
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            // print j-th character in i-th string (multi-dimensional array)
            printf("%c", argv[i][j]);
        }
        printf(" ");
    }
    printf("\n");
}

// main is always returning something, but doing it secretly, it is an int, but what int?
// commonly in programming, if nothing has gone wrong, programs and functions return 0, all is well