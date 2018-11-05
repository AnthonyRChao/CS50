#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number: ");
    int x = get_int();
    switch(x)
    {
        case 1:
            printf("1\n");
            break;
        case 2:
            printf("2\n");
            break;
        default:
            printf("done\n");
    }
}
