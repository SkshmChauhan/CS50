//
// Created by saksham on 21-06-2021.
//

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int get_letters(string s, int len);
int get_words(string s, int len);
int get_sentences(string s, int len);


int main(void)
{
    // Taking string input:
    string s = get_string("Text: ");
    int len = strlen(s);

    // Calling functions:
    int letters = get_letters(s, len);
    int words = get_words(s, len);
    int sentences = get_sentences(s, len);

    // Printing the data:
    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);

    // Calculating L and S:
    float ll = ((float) letters / words) * 100;
    float ss = ((float) sentences / words) * 100;
    // printf("L: %f\n", ll);
    // printf("S: %f\n", ss);

    float index = (0.0588 * ll) - (0.296 * ss) - 15.8;
    // printf("Index: %f\n", index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %i\n", (int) round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int get_letters(string s, int len)
{
    int letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(s[i]))
        {
            letters++;
        }
    }
    return letters;
}

int get_words(string s, int len)
{
    int words = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(s[i]) || s[i] == '-' || s[i] == 39)
        {
            continue;
        }
        else
        {
            if (isalpha(s[i - 1]))
            {
                words++;
            }
        }
    }
    return words;
}

int get_sentences(string s, int len)
{
    int sentences = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

