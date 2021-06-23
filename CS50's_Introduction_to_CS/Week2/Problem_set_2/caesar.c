//
// Created by saksham on 23-06-2021.
//

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


bool validateKey(string s);
string get_cipher(string plain, string key);


int main(int argc, string argv[])
{
    // Checking the number of arguments:
    if (argc <= 1 || argc >= 3)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        // Validating number of letters in the key:
        if (validateKey(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // Computing and printing cipher text:
            string plain = get_string("plaintext: ");
            string cipher = get_cipher(plain, argv[1]);
            printf("ciphertext: %s\n", cipher);
            return 0;
        }
    }
}

// Validating key and checking for alphabetical letters:
bool validateKey(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isdigit(s[i]))
        {
            return true;
        }
    }
    return false;
}

// Function for computing cipher text.
string get_cipher(string plain, string key)
{
    string cipher = plain;
    int ikey = atoi(key);
    ikey = ikey % 26;
    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        if (isalpha(plain[i]))
        {
            int ascii = plain[i];
            // printf("Original=> %c - %i\n", plain[i], ascii);
            ascii = ascii + ikey;
            if (islower(plain[i]) && ascii > 122)
            {
                ascii = ascii - 26;
            }
            else if (isupper(plain[i]) && ascii > 90)
            {
                ascii = ascii - 26;
            }
            cipher[i] = (char) ascii;
            // printf("Cipher=> %c - %i\n", cipher[i], cipher[i]);
        }
        else
        {
            // printf("Current Non-alphabetical character: %c\n", plain[i]);
            cipher[i] = plain[i];
        }

    }
    return cipher;
}

// plaintext:  hello, world
// ciphertext: uryyb, jbeyq
// ciphertext: uryyb, jbeyq

// plaintext:  be sure to drink your Ovaltine
// ciphertext: or fher gb qevax lbhe Binygvar
// ciphertext: or fher gb qevax lbhe Binygvar
