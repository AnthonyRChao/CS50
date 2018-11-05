#include <stdio.h>

int main(void)
{
    // declare array, array size and min
    int values[] = { 4, 2, 1, 3 };
    int n = 4;
    int min = values[0];

    // iterate
    for (int i = 0; i < n; i++)
    {

        // re-asssign min
        printf("Loop #%i\n", i);
        if (values[i] < min)
        {
            printf("\tOld min is %i\n", min);
            min = values[i];
            printf("\tNew min is %i\n", min);
        }
    }

    printf("%i\n", min);
}