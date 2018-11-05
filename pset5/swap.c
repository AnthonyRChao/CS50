#include <stdio.h>

void swap(int *a, int *b)
{
    printf("I'm inside a function! a is %i, b is %i \n", *a, *b);

    int temp = *a;
    *a = *b;
    *b = temp;

    printf("I'm inside a function! swapping! \n");
    printf("I'm inside a function! a is %i, b is %i \n", *a, *b);
}

int main()
{
    int x = 5;
    int y = 10;

    printf("x is %i, y is %i \n", x, y);
    swap(&x, &y);
    printf("x is %i, y is %i \n", x, y);

    return 0;
}