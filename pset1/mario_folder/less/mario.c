#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User input
    printf("Enter desired half-pyramid height.\n");
    int height = get_int();

    // Data validation
    while ( height < 0 || height > 23 )
    {
        printf("Retry: ");
        height = get_int();
    }

    // Outer loop determines number of output lines
    for ( int i = 0; i < height; i++ )
    {
        // First inner loop prints decreasing number of spaces
        for ( int j = height; j > i + 1; j-- )
        {
            printf(" ");
        }

        // Second inner loop prints out increasing number of octothorpes
        for ( int k = 0; k < i + 2; k++ )
        {
            printf("#");
        }

        // New line after inner loops complete
        printf("\n");
    }
}
