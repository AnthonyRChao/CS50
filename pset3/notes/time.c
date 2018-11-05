#include <stdio.h>
#include <time.h>

int main (void)
{
    // print time in seconds from 1 Jan 1970
    float n = time(NULL);
    printf("%.2f\n", n);
}