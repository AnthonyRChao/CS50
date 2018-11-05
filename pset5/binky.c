#include <stdio.h>
#include <stdlib.h>

int main()
{
    // give me space for an address
    // go there, but you have no idea where you are going
    int *x;
    int *y;

    x = malloc(sizeof(int));
    *x = 42;

    *y = 13;

    y = x;

    *y = 13;
}

