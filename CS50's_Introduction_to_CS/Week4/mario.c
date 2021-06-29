//
// Created by saksham on 30-06-2021.
//

#include <cs50.h>
#include <stdio.h>

void draw(int h);
void recursivedraw(int h);

int main(void)
{
    int height = get_int("Height: ");
    recursivedraw(height);
}

void draw(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("# ");
        }
        printf("\n");
    }
}

void recursivedraw(int h)
{
    if (h == 0)
    {
        return;
    }
    recursivedraw(h - 1);
    for (int j = 0; j < h; j++)
    {
        printf("# ");
    }
    printf("\n");
}