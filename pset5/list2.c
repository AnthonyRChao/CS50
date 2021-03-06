// Implements a list of unique numbers using a linked list

#include <cs50.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // memory for numbers
    node *numbers = NULL:

    // Prompt for numbers (until EOF)
    while (true)
    {
        // Prompt for number
        int number = get_int("number: ");

        // Check for EOF
        if (number == INT_MAX)
        {
            break;
        }

        // Check whether number is already in list
        bool found = false;
        for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->number == number)
            {
                found = true;
                break;
            }
        }

        // If number not found in list, add to list
        if (!found)
        {
            // Allocate sapce for number
            node *n = malloc(sizeof(node));
            if (!n)
            {
                return 1;
            }

            // Add number to list
            n->number = number;
            n->next = NULL;
            if (numbers)
            {
                for (node *ptr = numbers; ptr != NULL; ptr = ptr->next)
                {
                    if (ptr->next == NULL) // !ptr->next
                    {
                        ptr->next = n;
                        break;
                    }
                }
            }
            else
            {
                numbers = n;
            }
        }

        ...

        print numbers

        ...


    // Free memory
    node *ptr = numbers;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}