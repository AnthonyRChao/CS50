// selection sort implementation, O(n^2)

#include <stdio.h>

int main(void)
{
    int values[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int n = 10;
    int idx, temp;

    // print original array
    printf("Original Array: [ ");
    for (int h = 0; h < n; h++)
    {
        printf("%i ", values[h]);
    }

    printf("]\n");

    // iterate, n-1 in order to stop before last value
    for (int i = 0; i < n - 1; i++)
    {
        // set idx as min index
        idx = i;

        // iterate through values right of values[i] to check for new min
        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[idx])
            /*
            use values[idx] not values[i] here
            because i increments at each iteration
            whereas idx changes only if values[j] < values[idx]
            */
            {
                // set idx to new min index
                idx = j;
            }
        }

        if (idx != i) // if new min (idx) doesn't equal old min (i)
        {
            // swap values[idx] and values[i]
            printf("\tSwapping: %i & %i\n", values[idx], values[i]);
            temp = values[idx];
            values[idx] = values[i];
            values[i] = temp;
        }

        // print altered array
        printf("Iteration %i: [ ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%i ", values[k]);
        }

        printf("]\n");
    }

    return 0;
}
