//
// Created by saksham on 20-06-2021.
//

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = "HI!";
    for (int i = 0; i < 6; i++)
    {
        printf("Char: %c\t||\tInteger: %i\n", s[i], s[i]);
    }
}

