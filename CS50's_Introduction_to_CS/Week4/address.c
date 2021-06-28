//
// Created by saksham on 29-06-2021.
//

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("Value of n: %i\n", n);
    printf("Address of n: %p\n", p);
    printf("Value of n: %i\n", *p);
    printf("Pointer to Address of n: %i\n", *&n);

    char *s = "HI!";
    printf("\n%s\n", s);
    printf("%p\n", s);
    printf("%c or %c\n", *s, s[0]);
    printf("%c or %c\n", *(s+1), s[1]);
    printf("%c or %c\n", *(s+2), s[2]);
    printf("%i or %i\n", *(s+3), s[3]);

    // Will probably provide segmentation fault
    // printf("%i or %i\n", *(s+1000), s[1000]);

    // printf("%c\n", s[1]);
    // printf("%c\n", s[2]);
}