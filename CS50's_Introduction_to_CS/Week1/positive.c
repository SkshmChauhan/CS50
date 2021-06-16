//
// Created by saksham on 16-06-2021.
//

#include <stdio.h>
#include <cs50.h>

int get_positive_int(int);

int main(void)
{
    int i = get_positive_int();
    printf("%i\n", i);
}

int get_positive_int(int){
    int n;
    do{
        n = get_int("Enter the number:")
    }while(n < 1);
    return n;
}
