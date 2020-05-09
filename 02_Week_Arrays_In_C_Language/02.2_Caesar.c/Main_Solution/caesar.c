// Encodes text into ciphered one using key from command-line

// Command libraries includes
#include <stdio.h>
#include <cs50.h> // get_string() library
#include <string.h> // strlen() library
#include <stdlib.h> // atoi() library
#include <ctype.h> // isalpha(), isupper() library

// Variables declaration
int k;
string text;

// Functions declaration
int cipher_encode(void);

// Main program
int main(int argc, string args[])
{
    //-------------------------------------------
    // (1) Checking arguments in command-line
    // (1.1) if command-line has only one or more than 2 arguments then return mistake
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    // (1.2) if command-line argument is not of number value (not text) and return mistake
    if (atoi(args[1]) <= 0)
    {
        printf("Usage: ./caesar key (any positive integer number)\n");
        return 1;
    }

    //-------------------------------------------
    // (2) Convert char argument in command-line into integer one
    // if command-line key k is > 26, store the division remainder instead
    k = atoi(args[1]) % 26;

    //-------------------------------------------
    // (3) Get any plaintext input for conversion
    text = get_string("plaintext: ");

    //-------------------------------------------
    // (4) Print the ciphered text
    // (4.1) print name for encoded text
    printf("ciphertext: ");
    // (4.2) calling function defined below to print ciphered letters
    cipher_encode();
}

//----------------------------------------------------------------
//----------------------------------------------------------------
//                          FUNCTIONS
//----------------------------------------------------------------

// (4.2) Function definition for encoding the plaintext into ciphertext
int cipher_encode(void)
{
    // Get length of text string and check every letter for an alphabetic character using isalpha()
    // and using isupper() to check for an uppercase letter
    for (int i = 0; i < strlen(text); i++)
    {
        // If element is not letter then print element as it is (unencoded)
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }

        // isupper() checks for an uppercase letter in text is out of ASCII UPPER letters range
        int ascii_offset = isupper(text[i]) ? 65 : 97;

        // pi is the i-th character in text
        int pi = text[i] - ascii_offset;

        // Calculate remainder when dividing by 26 for ciphertext ci
        // by “rotating” each letter pi of the text by k positions
        int ci = (pi + k) % 26;

        // Print every char converted with key
        printf("%c", ci + ascii_offset);
    }
    // Print line return
    printf("\n");
    return 0;
}