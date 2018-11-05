#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get input from user
    string s = get_string();

    // initialize an integer n as 0
    int n = 0;

    // increment n until s[n] != '\0'
    while (s[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);
}