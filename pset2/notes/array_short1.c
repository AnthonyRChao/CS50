// array declarations: type name[size];

#include <stdio.h>

int main(void)
{
    int array[100];
    int counter = 0;

    for (int i = 0; i < 100; i++)
    {
        array[i] = counter;
        counter++;
        printf("loop %i, array[%i] = %i\n", i, i, i);
    }
}