//
// Created by saksham on 16-06-2021.
//

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Getting char input from user.
    char c = get_char("Do you agree? ");

    // Analysing user input:
    if (c == 'y' || c == 'Y'){
        printf("Agreed!!\n");
    } else if (c == 'n' || c == 'N') {
        printf("Not agreed. :(\n");
    } else {
        printf("Invalid Input!!\n");
    }
}

