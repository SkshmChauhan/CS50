//
// Created by saksham on 20-06-2021.
//

#include <stdio.h>
#include <cs50.h>

// Prototype of get_negative_int
int get_negative_int(void);

int main(void)
{
    // Get negative integer from user.
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        n = get_int("Negative Integer: ");
    }while(n >= 0);
    return n;
}



