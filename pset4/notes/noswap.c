/**
 * Why do x and y not swap?
 * Try running debug50 after setting a breakpoint at the first "printf"
 */

#include <stdio.h>

void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i\n", x);
    printf("y is %i\n", y);
    printf("Swapping...\n");
    swap(x, y);
    printf("Swapped.\n");
    printf("x is %i\n", x);
    printf("y is %i\n", y);
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/*
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
     b = tmp;
}
*/
