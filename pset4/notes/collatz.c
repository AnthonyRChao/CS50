#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = 0;
    printf("Enter an integer.\n");
    scanf("%i", &n);
    printf("%i steps required.\n", collatz(n));
    return 0;
}

int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;
    // even recursive case
    else if (n % 2 == 0)
        // printf("n is: %i\n", n);
        return 1 + collatz(n / 2);
    // odd recursive case
    else
        // printf("n is: %i\n", n);
        return 1 + collatz(3 * n + 1);
}˜