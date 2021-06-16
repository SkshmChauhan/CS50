//
// Created by saksham on 16-06-2021.
//

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (start > end);

    // Calculate number of years until we reach threshold
    int years = 0;
    int current  = start;
    while
            (current < end)
    {
        current = current + (current / 3) - (current / 4);
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
