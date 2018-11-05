#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes, bottles;

    printf("Minutes: ");
    minutes = get_int();
    bottles = minutes * 192 / 16;
    printf("Bottles: %i\n", bottles);
}