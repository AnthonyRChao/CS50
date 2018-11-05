#include <stdio.h>

int fact(int x);

int main(void)
{
    int n = 0;
    printf("Enter a positive integer n.\n");
    scanf("%i", &n);
    printf("Factorial of %i is: %i\n", n, fact(n));
    return 0;
}

int fact(int n)
{
    // base case
    if (n == 1)
        return 1;

    // recursive case
    else
        return n * fact(n - 1);
}