//
// Created by saksham on 24-06-2021.
//

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
        person;

int main(void)
{
    // string names[] = {"Brian", "David"};
    // string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

    person people[2];

    people[0].name = "Brian";
    people[0].number = "1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        // if(strcmp(names[i], "David") == 0)
        // {
        //     printf("Found %s\n", numbers[i]);
        //     return 0;
        // }

        if (strcmp(people[i].name, "David") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}


