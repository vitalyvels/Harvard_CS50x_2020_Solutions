// Encodes text into ciphered one using 26 alphabet letter key from command-line

// Command libraries includes
#include <stdio.h>
#include <cs50.h> // get_string() library
#include <string.h> // strlen() library
#include <stdlib.h> // atoi() library
#include <ctype.h> // isalpha(), isupper() library

// Variables declaration
int c, i, j, l, k, n, count;
char az1[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char az2[26] = "abcdefghijklmnopqrstuvwxyz";
char key_UPPER[25];
char key_lower[25];
string text;

// Main program
int main(int argc, char *argv[])
{
    //-------------------------------------------
    // (1) Checking arguments in command-line for mistakes
    //-------------------------------------------
    // (1.1) if command-line has only one or more than 2 arguments then return mistake
    if (argc != 2)
    {
        printf("Usage: ./substitution key (enter 26 letters of alphabet)\n");
        return 1;
    }

    //-------------------------------------------
    // (1.2) if command-line argument is not of alphabet length of 26 letters then return mistake
    if (strlen(argv[1]) != 26) //  || atoi(args[1]) <= 0 || atoi(args[1]) > 0
    {
        printf("Your key is %lu letters long.\nUsage: ./substitution key (enter 26 letters of alphabet)\n", strlen(argv[1]));
        return 1;
    }
    //-------------------------------------------
    // (1.3) if command-line argument has nonletter characters in key and return mistake
    for (k=0, n=strlen(argv[1]); k<n; k++)
    {
        if (!isalpha(argv[1][k]))
        {
            printf("Your key has nonletter element(s).\nUsage: ./substitution key (enter 26 letters of alphabet)\n");
            return 1;
        }
    }
    //-------------------------------------------
    // (1.4) if command-line argument has duplicate characters in key and return mistake
    // (1.4.1) Convert command-line key into Upper and lowercase array
    for (c=0; c<26; c++)
    {
        key_UPPER[c] = toupper((int)argv[1][c]);
        // printf("%c\n", key_UPPER[c]);
        key_lower[c] = tolower((int)argv[1][c]);
        // printf("%c\n", key_lower[c]);
    }
    // printf("key_UPPER = %s\nkey_lower = %s\n", key_UPPER, key_lower);

    // (1.4.2) if command-line argument has duplicate characters in key and return mistake
    for (j=0; j<26; j++)
    {
        count = 0;
        for (k=0, n=strlen(argv[1]); k<n; k++)
        {
            if (key_UPPER[k] == az1[j])
            {
                count++;
            }
        }
        // printf("Count for letter %c is %i\n", az1[j], count);
        if (count > 1)
        {
            printf("Your key has duplicate characters.\nUsage: ./substitution key (enter 26 nonduplicated letters of alphabet)\n");
            return 1;
        }
    }
    //-------------------------------------------
    // (2) Get any plaintext input for conversion
    text = get_string("plaintext: ");
    //-------------------------------------------
    // (3) Encode text into ciphertext
    char ciphertext[strlen(text)];
    printf("ciphertext: ");
    for (i=0; i<strlen(text); i++)
    {
        // If element is not letter then print element as it is (unencoded)
        if (!isalpha(text[i]) && text[i] != '!')
        {
            printf("%c", text[i]);
            continue;
        }

        for (j=0; j<26; j++)
        {
            if (text[i] == az1[j])
            {
                ciphertext[i] = key_UPPER[j];
                printf("%c", ciphertext[i]);
            }
            if (text[i] == az2[j])
            {
                ciphertext[i] = key_lower[j];
                printf("%c", ciphertext[i]);
            }
        }
    }
    printf("\n");
}