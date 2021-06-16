//
// Created by saksham on 16-06-2021.
//

#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // Taking input from user
    int num = 0;
    do
    {
        num = get_int("Enter the number: ");
    }
    while (num < 1 || num > 8);

    // Outer loop for the number of rows.
    for (int i = 0; i < num; i++)
    {
        // Adding space to the rows.
        for (int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        // Adding the hashes on left side.
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}