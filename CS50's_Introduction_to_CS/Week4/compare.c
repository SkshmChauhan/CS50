//
// Created by saksham on 29-06-2021.
//

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Integer Part:

    // int i = get_int("i: ");
    // int j = get_int("j: ");

    // if(i == j)
    // {
    //     printf("Same\n");
    // }
    // else
    // {
    //     printf("Different\n");
    // }

    // String Part:
    char *s = get_string("s: ");
    char *t = get_string("s: ");

    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    printf("%s || %s\n", s, t);
    printf("%p || %p\n", s, t);

}