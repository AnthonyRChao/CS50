#include <cs50.h>
#include <stdio.h>
#include <time.h>

int countdown(int n);

int main(void)
{
    int n;

    // get valid user input
    do
    {
        printf("Enter positive integer: ");
        n = get_int();
    } while (n < 1);

    // call countdown on n
    countdown(n);
}

int countdown(int n)
{
    // base case
    if (n == 0) return 0;

    printf("%i\n", n);

    // recursive case
    return countdown(n - 1);
}