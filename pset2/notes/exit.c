#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command line argument\n");

        // exit code normally useful to programmer / company
        return 1;
    }

    printf("Hello, %s\n", argv[1]);
    return 0;
}

// debugging
// cryptography
// strings, under the hood
// access individual characters in string
// command line arguments
// array is a chunk of memory whose elements are contiguous, and generally of the same data type
// array == our first data structure, start to solve problems with code that came that came intuitively in week 0 (phone book example)
// divide and conquer / binary search / phone book was sorted