hashtable - how can this data structure approach linear O time

visual and conceptual equivalent of placing things in buckets. "bucketinzing" all your items.

it is not an array

hashing is the intersting part

Linear probing - hash to somewhere, collision, probe further, put somewhere,
close to constant time decision making

hash table & a linked list

hash table is an array that does not store strings, it only stores pointers!
those pointers point to the beginnings of linked lists!

dichotomy - asymptotic running time and the actual running time. just because
it's n^2 doesn't mean it's bad, only if data is big

n^2 vs. n^2 / 2 - there is a difference

trie (retrieval)

- tree whose nodes are arrays (good for words, dictionaries)

- spell checker

build dictionary

arrays of pointers to other nodes

breadcrumbs from one node to another, eventually at the "sentinel" value (TRUE), then
by storing yes or no, you can implicitly reveal that "MAXWELL" is a word

inserting and looking up a name in trie, what is its running time?

root > pointer to M > pointer to A > Pointer to X > ... > pointer to True

numbers have nothing to do with how many words are in the trie ...

there might be thousands of actual words, but doesn't matter how many data elements,
that is what is powerful. if there is an upper bound, there is a constant value, meaning
inserting / searching / removing depends on length of name, but not on how many pieces of
data in the data structure, thus we have constant time.

pointers, malloc, data structures to build cool stuff! space, efficiency, good design.

in C, we have new syntax to represent data strcutures, pointers, structs, malloc, and
abstract data types, solve problems

Shorts

Singly Linked Lists
typedef struct sllist
{
    VALUE val;
    struct sllist* next;
}
sllnode;
}
