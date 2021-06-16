//
// Created by saksham on 16-06-2021.
//

#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    // Declaring variables
    int count = 0, arr[17], pos = 0;
    long rev = 0, remainder;
    long number = get_long("Number: ");
    long temp = number;
    int size = trunc(log10(number)) + 1;

    // Analysing size of the number:
    if (size < 13)
    {
        printf("INVALID\n");
    }
    else
    {
        while (number != 0)
        {
            remainder = number % 10;
            rev = rev * 10 + remainder;
            arr[pos] = remainder;
            pos++;
            number /= 10;
        }
        int sum = 0;
        for (int i = 1; i < pos; i += 2)
        {
            arr[i] *= 2;
            if (arr[i] <= 9)
            {
                sum += arr[i];
            }
            else
            {
                int waste = arr[i];
                while (waste != 0)
                {
                    sum += waste % 10;
                    waste /= 10;
                }
            }
        }
        for (int i = 0; i < pos; i += 2)
        {
            sum += arr[i];
        }
        if (sum % 10 == 0)
        {
            int startNum = 0;
            // Classifying cards:
            for (int i = 0; i < 2; i++)
            {
                startNum = startNum * 10 + (rev % 10);
                rev /= 10;
            }
            if ((startNum == 34 || startNum == 37) && pos == 15)
            {
                printf("AMEX\n");
            }
            else if (startNum >= 51 && startNum <= 55 && pos == 16)
            {
                printf("MASTERCARD\n");
            }
            else if (startNum / 10 == 4 && (pos == 13 || pos == 16))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }

}

