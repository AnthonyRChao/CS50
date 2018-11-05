#include <stdio.h>

int main(void)
{
    int arr[10] = { 10, 9, 7, 8, 3, 5, 4, 2, 1, 6 };
    int n = 10;
    int min;

    // print original arr
    for (int a = 0; a < n; a++)
    {
        printf("%i ", arr[a]);
    }
    printf("\n");

    // loop through array up until last item
    for (int i = 0; i < n -1; i++)
    {
        // set item at i as min
        min = i;

        // loop through values to the right of i
        for (int j = i + 1; j < n; j++)
        {
            // if value at j is smaller than value at min, set min to j
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        // executie block if arr[min] is different from arr[i]
        if (min != i)
        {
            // swap locations with use of temp variable
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    for (int b = 0; b < n; b++)
    {
        printf("%i ", arr[b]);
    }
    printf("\n");
}
