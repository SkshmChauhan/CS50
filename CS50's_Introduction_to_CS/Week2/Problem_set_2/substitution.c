//
// Created by saksham on 22-06-2021.
//

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


bool validateKey(string s);
string get_cipher(string plain, string key);
string get_key(string arr);


int main(int argc, string argv[])
{
    // Checking the number of arguments:
    if (argc <= 1 || argc >= 3)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        // Validating number of letters in the key:
        if (strlen(argv[1]) < 26 || validateKey(argv[1]))
        {
            printf("Key must contain 26 characters.\n");
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

// Validating key and checking for non-alphabetical letters:
bool validateKey(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (!isalpha(s[i]))
        {
            return true;
        }
        for (int j = i + 1; j < len; j++)
        {
            if (s[j] == s[i])
            {
                return true;
            }
        }
    }
    return false;
}

// Function for computing cipher text.
string get_cipher(string plain, string key)
{
    string cipher = plain;
    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        // Checking for alphabets:
        if (isalpha(plain[i]))
        {
            int index = plain[i];
            // Checking for uppercase.
            if (isupper(plain[i]))
            {
                index = index - 65;
                cipher[i] = toupper(key[index]);
            }
                // Condition for lowercase.
            else
            {
                index = index - 97;
                cipher[i] = tolower(key[index]);
            }
            // printf("Index of %c is : %i\n", plain[i], index);
        }
        else
        {
            cipher[i] = plain[i];
        }
    }
    return cipher;
}


