#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // if the argument count is 2
    if (argc == 2)
    {
        // print the second item in the argument vector
        printf("Hello %s\n", argv[1]);
    }
    else
    {
        // otherwise print "Hello World"
        printf("Hello World\n");
    }
}


// what is argc? it is an integer, the number of words (arguments) the user provided at the prompt, including the progam's name
// what is argv? argument vector aka an array, list of similar values, back to back to back
// an array is a chunk of contiguous memory, each of whose elements are back to back to back, and generally the same type
// "Zamyla'\0'" is an array of characters. each character takes up a byte. a string is just an array of chars (char being a native data type)
