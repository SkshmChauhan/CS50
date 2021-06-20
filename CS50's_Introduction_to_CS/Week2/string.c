//
// Created by saksham on 20-06-2021.
//

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Taking input from user.
    string s = get_string("Input:\t");
    printf("Output: ");

    // Looping through the string and print one char at a time.
    // for (int i = 0; s[i] != '\0'; i++)
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}
