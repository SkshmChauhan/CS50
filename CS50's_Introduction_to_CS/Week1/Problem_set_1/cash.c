//
// Created by saksham on 16-06-2021.
//

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //  (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    int input = round(dollars * 100);

    int coins = 0;

    while (input > 0)
    {
        if (input >= 25)
        {
            input = input - 25;
        }
        else if (input >= 10)
        {
            input = input - 10;
        }
        else if (input >= 5)
        {
            input = input - 5;
        }
        else
        {
            input = input - 1;
        }
        coins++;
    }
    printf("%i\n", coins);
}
