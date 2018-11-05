/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>

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

    // implement linear search first, O(n), re-implement binary search after
    // for (int i = 0; i < n; i++)
    // {
    //     // if i-th item in values equals value, return true
    //     if (value == values[i]) return true;
    // }
    // return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm

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

    // bubble sort O(n^2)

    // insertion sort O(n^2)

    // merge sort O(log n)

    return;
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
        return binary_search(value, values, n, low, mid - 1);
    }
    // recursive case 2
    else
    {
        // redfine low as one right of prior mid
        return binary_search(value, values, n, mid + 1, high);
    }
}
