#include <stdio.h>

int main(void)
{
    int x = 5; // initialize integer x with value 5
    printf("x is %i\n&x is %p\n\n", x, &x);

    int *px; // declare pointer variable px
    px = &x; // define pointer variable
    printf("px is %p\n", px);
    printf("&px is %p\n\n", &px);
}