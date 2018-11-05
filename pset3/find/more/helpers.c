/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

bool binary_search(int value, int values[], int n, int low, int high);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm, O(log n)
    int low = 0;
    int high = n - 1;

    if (binary_search(value, values, n, low, high))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // count sort implementation
    const int MAX = 65536;

    // // print original array
    // for (int j = 0; j < n; j++)
    // {
    //     printf("%i ", values[j]);
    // }
    // printf("\n\tprinted values[]!\n");

    // create countArr
    int countArr[MAX];
    for (int i = 0; i < MAX; i++)
    {
        countArr[i] = 0;
        // printf("countArr[%i] = %i\n", i, countArr[i]);
    }
    // printf("\tcreated countArr!\n");

    // iterate over original array, increment countArr
    for (int k = 0; k < n; k++)
    {
        countArr[values[k]]++;
        // printf("incremented countArr[%i]\n", values[k]);
    }

    // // print updated countArr
    // for (int l = 0; l < MAX; l++)
    // {
    //     printf("countArr[%i] = %i\n", l, countArr[l]);
    // }
    // printf("\tupdated countArr!\n");

    // accumatively add each pair of consecutive values in countArr
    // printf("countArr[%i] = %i\n", 0, countArr[0]);
    for (int m = 1; m < MAX; m++)
    {
        if (m < MAX )
        {
            countArr[m] = countArr[m] + countArr[m-1];
            // printf("countArr[%i] = %i\n", m, countArr[m]);
        }
    }
    // printf("\tadded consecutive values in countArr!\n");

    // shift countArr over by one index
    for (int p = MAX - 1; p > 0; p--)
    {
        countArr[p] = countArr[p-1];
    }
    countArr[0] = 0;

    // // print shifted countArr
    // for (int q = 0; q < MAX; q++)
    // {
    //     printf("countArr[%i] = %i\n", q, countArr[q]);
    // }
    // printf("\tshifted countArr!\n");

    // create newArr to hold sorted elements
    int newArr[n];

    // iterate through original array and sort elements with values, countArr & newArr
    for (int r = 0; r < n; r++)
    {
        // find index of countArr that corresponds with element in values
        newArr[countArr[values[r]]] = values[r];
        countArr[values[r]]++;
    }

    // // print newArr
    // for (int s = 0; s < n; s++)
    // {
    //     printf("newArr[%i] = %i\n", s, newArr[s]);
    // }
    // printf("\tprinted newArr!\n");

    // copy integer array to another array
    for (int t = 0; t < n; t++)
    {
        values[t] = newArr[t];
    }

    // print values[]
    for (int u = 0; u < n; u++)
    {
        printf("values[%i] = %i\n", u, values[u]);
    }
    printf("\tsorted values[]!\n");

}

// binary search implementation
bool binary_search(int value, int values[], int n, int low, int high)
{
    int mid = (low + high) / 2;

    // base case
    if (low > high)
    {
        return false;
    }
    else
    {
        // found value
        if (values[mid] == value)
        {
            // printf("Value found at index %i.\n", mid);
            return true;
        }
        // recursive case 1
        else if (values[mid] > value)
        {
            // redefine high as left of prior mid
            printf("low: %i, high: %i\n" , low, high);
            return binary_search(value, values, n, low, mid - 1);
        }
        // recursive case 2
        else
        {
            // redfine low as one right of prior mid
            printf("low: %i, high: %i\n" , low, high);
            return binary_search(value, values, n, mid + 1, high);
        }
    }
}

/*
// selection sort O(n^2)

// iterate through values[] up until last item
for (int i = 0; i < n - 1; i++)
{
    // set index at i to min
    int min = i;
    // check values[j], right of values[i] for new min
    for (int j = i + 1; j < n; j++)
    {
        if (values[j] < values[min])
        {
            min = j;
        }
    }
    // check if values[min] and values[i] differ, if they do, swap
    if (min != i)
    {
        int temp = values[min];
        values[min] = values[i];
        values[i] = temp;
    }
}
return;
*/