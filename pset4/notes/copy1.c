/**
 * Why is "s" being capitalized as well?
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("s: ");
    string s = get_string();
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc((strlen(s) + 1) * sizeof(char));
    if (t == NULL)
    {
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i]  = s[i];
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);

    return 0;
}

    //string t = s;
    // fn to ask OS, please give me a bunch of bytes of memory
    // goal is to copy a string s and stores copy in t
    // can't just do t = s, that is just the addresses
    // so how do you get a complete copy?
    // why strlen(s) + 1, if we don't ask for the + 1, we're
    // not going to get the null terminator
    // * sizeof(char) ... give me 7 times the size of a char
    // really equivalent to malloc(7);
    // find a chunk of memory, contiguous memory, grab 7 bytes
    // and ... return a chunk of memory to your main function
    // malloc returns the address of the first byte of memory
    // but unlike a string, unlike get_string, malloc gives
    // a set of memory
    // go too far past your memory can give you a segmentation fault
    //