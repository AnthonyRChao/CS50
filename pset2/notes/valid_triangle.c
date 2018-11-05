#include <cs50.h>
#include <stdio.h>

// declaration: refers to introduction of a new name in the program
bool valid_triangle(float x, float y, float z);

int main(void)
{
    // get input from user
    float x = get_float();
    float y = get_float();
    float z = get_float();
    bool result = valid_triangle(x, y, z);

    // a ternary operator is an expression instead of a statement, it can exist on the "right hand side"
    printf("%s\n", result ? "true" : "false");
}

// definition: a definition of a previously declared name
bool valid_triangle(float x, float y, float z)
{
    // check that sides are positive
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    // check sum of any two sides is greater than the third
    if ((x + y <= z || x + z <= y || y + z <= x))
    {
        return false;
    }

    return true;
}

// initialization: refers to the "assignment" of a value, at construction time