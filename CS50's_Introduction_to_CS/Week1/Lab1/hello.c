//
// Created by saksham on 16-06-2021.
//

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // getting input from user.
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}