//
// Created by saksham on 16-06-2021.
//

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Getting numbers from input:
    int x = get_int("x: ");
    int y = get_int("y: ");

    // Compare x and y
    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}