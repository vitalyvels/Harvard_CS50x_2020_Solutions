// C program to find last occurrence of an array of given nonsentence words in given text
// NonSentence Words means words that may mistakenly missmatched as the end of sentence
// because of comma at the end of the word (i.e. Mr., Mrs. etc.)

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Variables declaration
int i, j, k, m, x, nonsentence, found, text_length;
string text;

// Function declaration
int nonsentense_calc(void);

//-----------------------
//         Main
//-----------------------
int main(void)
{
    // Input string and word from user
    text = get_string("Text: ");
    nonsentence = nonsentense_calc();
    printf("\n NonSentences found %i times in text \n", nonsentence);
}

//------------------------
//       FUNCTIONS
//------------------------
// The function finds last occurrence of an array of given nonsentence words in given text
// NonSentence Words means words that may mistakenly missmatched as the end of sentence
// because of comma at the end of the word (i.e. Mr., Mrs. etc.)

int nonsentense_calc(void)
{
    // // Input string and word from user
    // text = get_string("Text: ");

    // Find length of text
    text_length  = strlen(text) + 1;

    // Enter nonsentence words into array
	char words_array[][10] = { "Mr. ", "Mrs. ", "MR. ", "MRS. ", "v. ", "vs.", "U.S. ", "U.S.A. "};

	// Count the quantity of words in array
	int words_array_count = sizeof(words_array) / 10;
	// printf("Elements in the array: %i\n", words_array_count);

	// Detect the length of words in words_array and put lengths into new array
	long words_array_length[words_array_count];
	for (k=0; k<words_array_count; k++) //words_array_count; k++)
	{
		words_array_length[k] = strlen(words_array[k]);
        //printf("Length of %i word %s in array is %lu letters\n", k, words_array[k], words_array_length[k]);
	}

    //Run a loop from of text loking for the nonsentence words
    nonsentence = 0;
    for (m=0; m<words_array_count; m++)
    {
        for(i=0; i<text_length - words_array_length[m]; i++)
        {
            found = 0;
            // Match word at current position
            for(j=0; j<words_array_length[m]; j++)
            {
                // found = 0;
                // Count nonsentence if word matched in the text
                if (text[i + j] == words_array[m][j])
                    found  = found + 1;
                    // printf("[%i;%i] Letters for %lu found %d\n", i, j, words_array_length[m], found);
                    if (found == words_array_length[m])
                        nonsentence++;
            }
        }
    }

    // printf("NonSentences found %i times in text \n", nonsentence);

    return nonsentence;
}