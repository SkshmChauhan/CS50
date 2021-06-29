//
// Created by saksham on 30-06-2021.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Try changing integer to 3 and use valgrind ./memory
    char *s = malloc(4);
    s[0] = 'H';
    s[1] = 'I';
    s[2] = '!';
    s[3] = '\0';
    printf("%s\n", s);

    // One must use free when using malloc to avoid memory problems.
    free(s);
}