//
// Created by saksham on 20-06-2021.
//

#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void) {
    string s = get_string("Before: ");
    printf("After:  ");

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Naive Method:
        // if (s[i] >= 'a' && s[i] <= 'z')
        // {
        //     printf("%c", s[i] - 32);
        // }
        // else
        // {
        //     printf("%c", s[i]);
        // }

        // Using ctype library:
        // if (islower(s[i]))
        // {
        //     printf("%c", toupper(s[i]));
        // }
        // else
        // {
        //     printf("%c", s[i]);
        // }

        printf("%c", toupper(s[i]));
    }
    printf("\n");
}

