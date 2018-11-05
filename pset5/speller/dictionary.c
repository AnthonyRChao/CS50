// Implements a dictionary's functionality
#include "dictionary.h"

#define HASHTABLE_SIZE 65536

// define node struct, which contains a word and a pointer to next node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// define variable to count number of words in dictionary;
int numWords;

// define a hash table of HASHTABLE_SIZE
node *hashtable[HASHTABLE_SIZE];

// hash function source: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(needs_hashing); i < n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}

// global variable to determine if dictionary is loaded or not
bool loaded;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // create a char array to store the word to check
    int length = strlen(word);
    char word_copy[length + 1];

    // create a copy of const char *word to work with
    strcpy(word_copy, word);

    // set word_copy to all lower case
    for (int i = 0; i < length; i++)
    {
        word_copy[i] = tolower(word_copy[i]);
    }

    // add null terminator to end of word_copy
    word_copy[length] = '\0';

    // get hash value of word_copy
    int x = hash_it(word_copy);

    // create a cursor node and assign it to first node of relevant bucket
    node *cursor = hashtable[x];

    // iterate through linked list
    while (cursor != NULL)
    {
        // strcmp compares two strings: str1 and str2
        // strcmp will return 0 if the two strings are
        // equal, < 0 if str1 comes before str2 alphabetically,
        // and > 0 if str1 comes after str2 alphabetically.
        if (strcmp(word_copy, cursor->word) == 0)
        {
            // word in dictionary
            return true;
        }
        // check next word in node of linked list
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // iterate through dictionary
    while(true)
    {
        // malloc new node for each word
        node *new_node = malloc(sizeof(node));
        if(new_node == NULL)
        {
            printf("Could not malloc for new_node.\n");
            return false;
        }

        // scan word from dictionary into new_node->word
        fscanf(file, "%s", new_node->word);

        // set new_node pointer to NULL
        new_node->next = NULL;

        // if reached EOF, free node and break
        if (feof(file))
        {
            free(new_node);
            break;
        }

        // increment number of words loaded in
        numWords++;

        // hashtable[x] is the head pointer of linked list
        int x = hash_it(new_node->word);
        node *head = hashtable[x];

        // if bucket is empty, insert the node
        if (head == NULL)
        {
            hashtable[x] = new_node;
        }
        // if bucket not empty, assign new node->next to head pointer's pointee
        // assign head pointer to new pointee, new_node
        else
        {
            new_node->next = hashtable[x];
            hashtable[x] = new_node;
        }
    }

    loaded = true;

    // close dictionary
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded)
    {
        return numWords;
    }
    else
    {
        return false;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // loop through all nodes in hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // set a cursor pointer to traverse the linked list
        node *cursor = hashtable[i];
        if (hashtable[i] != NULL)
        {
            // define pointer to check each node
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    loaded = false;
    return true;
}
