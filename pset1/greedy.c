/* This program outputs how much change
   is owed and the minimum number of coins with
   which said change can be made */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int change, coins_to_add;
    int coin_counter = 0;
    int coin_array[4] = {25, 10, 5, 1};

    string names[4];
    names[0] = "quarters";
    names[1] = "dimes";
    names[2] = "nickels";
    names[3] = "pennies";

    do
    {
        printf("O hai! How much change is owed?\n");
        change = (int)round(get_float() * 100);
        // printf("%i\n", change);

    }
    while (change < 0);

    for (int i = 0; i < 4; i++)
    {
        coins_to_add = change / coin_array[i];
        coin_counter += coins_to_add;

        if (coins_to_add > 0)
        {
            change = change - (coins_to_add * coin_array[i]);
        }

        // printf("Loop: %i, ", i);
        // printf("coin_counter is: %i, ", coin_counter);
        // printf("coins_to_add is: %i, ", coins_to_add);
        // printf("change is: %i, ", change);
        // printf("coin_array[i] is: %i, ", coin_array[i]);
        // printf("names[i] is: %s\n", names[i]);

    }

    printf("%i\n", coin_counter);
    return 0;
}
