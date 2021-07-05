//
// Created by saksham on 05-07-2021.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // int list[3];

    // list[0] = 1;
    // list[1] = 2;
    // list[2] = 3;

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("%i\n", list[i]);
    // }

    // Using malloc to allocate an array.
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *temp = realloc(list, 4 * sizeof(int));
    if (temp == NULL)
    {
        free(list);
        return 1;
    }

    // This copying process is taken care of by realloc function.
    // for (int i = 0; i < 3; i++)
    // {
    //     temp[i] = list[i];
    // }
    temp[3] = 4;

    free(list);
    list = temp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", temp[i]);
    }

    free(list);
}
