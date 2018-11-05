#include <cs50.h>
#include <stdio.h>

float multiply_two_floats(float x, float y);
int add_two_ints(int a, int b);

int main(void)
{
    float num1 = get_float();
    float num2 = get_float();
    int num3 = get_int();
    int num4 = get_int();

    float product = multiply_two_floats(num1, num2);
    int sum = add_two_ints(num3, num4);

    printf("%f\n", product);
    printf("%i\n", sum);
}

float multiply_two_floats(float x, float y)
{
    return x * y;
}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}

