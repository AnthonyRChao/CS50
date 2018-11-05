#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User input
    printf("Enter desired half-pyramid height.\n");
    int max_height = get_int();

    // Data validation
    while ( max_height < 0 || max_height > 23 )
    {
        printf("Retry: ");
        max_height = get_int();
    }

    // Outer loop determines number of output lines
    for ( int i = 0; i < max_height; i++ )
    {
        // Inner Loop #1: Print out spaces
        for ( int j = max_height; j > i + 1; j-- )
        {
            printf(" ");
        }

        // Inner Loop #2: Print out octothorpes
        for ( int k = 0; k < i + 1 ; k++ )
        {
            printf("#");
        }

        // Print out two spaces
        printf("  ");

        // Inner Loop #3: Print out octothorpes
        for ( int k = 0; k < i + 1 ; k++ )
        {
            printf("#");
        }

        // New line after inner loops complete
        printf("\n");
    }
}