#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // prompt for a string of text
    string text = get_string("Text: ");

    // count letters out of alphabet array for upper and lower cases in the given paragraph of text
    char AZ1[25] = "ABCDEFGHIJKLMNOPRSTUVWXYZ"; // array of uppercase letters of alphabet
    char az2[25] = "abcdefghijklmnoprstuvwxyz"; // array of lowercase letters of alphabet
    int letters1 = 0, p; // letter counter declaration
    int i = 0;
    for (i = 0; text[i] != '\0';i++) // loop for checking for text element if it is character or not
    {
        for (p = 0; p < 25; p++)
        {
            if (text[i] == AZ1[p])
                letters1++;
            if (text[i] == az2[p])
                letters1++;
        }
    }
    printf("\n Letters in the text: %i\n", letters1);
}