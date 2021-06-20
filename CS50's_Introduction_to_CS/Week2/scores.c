//
// Created by saksham on 20-06-2021.
//

#include <stdio.h>
#include <cs50.h>

const int TOTAL = 4;

float average(int length, int array[]);

int main(void)
{
    // Declaring scores array using constant
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i++)
    {
        // Taking 4 scores input
        scores[i] = get_int("Score: ");
    }

    // Printing and calling average function.
    printf("Average: %f\n", average(TOTAL, scores));
}

float average(int length, int array[])
{
    int sum = 0;
    // Adding numbers from the array
    for (int i = 0; i < length; i++)
    {
        sum = sum + array[i];
    }
    // Returning value of average.
    return sum / (float)length;
}