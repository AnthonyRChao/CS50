// an array can not be copied to another array via the assignment operator "="
// the arrays elements need to be copied over via loop

// for example
int foo[5] = { 1, 2, 3, 4, 5 };
int bar[5]

// this would not work
bar = foo;

// we would have to do something like this instead
for (int j = 0; j < 5; j++)
{
    bar[j] = foo[j];
}