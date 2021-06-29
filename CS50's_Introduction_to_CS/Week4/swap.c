//
// Created by saksham on 30-06-2021.
//

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;
    printf("X: %i & Y: %i\n", x, y);
    swap(&x, &y);
    printf("X: %i & Y: %i\n", x, y);

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}