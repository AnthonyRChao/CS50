#include <stdio.h>

void swap(int *x, int *y);

int main(void)
{
    // declare ints a & b
    int a, b;

    // get user input
    scanf("%i", &a);
    scanf("%i", &b);

    // swap
    printf("a is: %i\n", a);
    printf("b is: %i\n", b);
    printf("\t*a is %p\n", &a);
    printf("\t*b is %p\n", &b);

    printf("swapping...\n");
    swap(&a, &b);

    printf("a is: %i\n", a);
    printf("b is: %i\n", b);
    printf("\t*a is %p\n", &a);
    printf("\t*b is %p\n", &b);

    printf("swapped!\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
