// Program for readability test grade calculation (the Coleman-Liau index)

// Command libraries includes
#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Variables declaration
int i, j, k, l, m, p, letters, words, sentences, nonsentence, found, text_length;
string text;

// Functions declaration
int words_calc(void);
int letters_calc(void);
int nonsentense_calc(void);
int sentences_calc(void);
int grade(void);

// Main program
int main(void)
{
    // 1) prompt for a string of text
    text = get_string("\nText: ");

    // 2) quantity of words in the text by counting spaces+1
    words_calc();

    // 3) quantity of letters in the text
    letters_calc();

    // 4) NonSentences' exclude Words with comma Mr./Mrs.
    nonsentense_calc();

    // 5) quantity of sentences by ./!/? +space+1
    sentences_calc();

    // 6) Coleman-Liau Index Grade index = 0.0588 * L - 0.296 * S - 15.8
    grade();
}

//----------------------------------------------------------------
//----------------------------------------------------------------
//                          FUNCTIONS
//----------------------------------------------------------------

// (2) Function for quantity of words in the text by counting spaces+1
int words_calc(void)
{
    words = 0;
    for (i = 0;text[i] != '\0';i++)
    {
        if (text[i] == ' ' && text[i+1] != ' ')
            words++;
    }
    words++;
    return words;
}
//---------------------------------------------------------
// (3) Function for quantity of letters in the text
int letters_calc(void)
{
    char az1[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char az2[26] = "abcdefghijklmnopqrstuvwxyz";
    letters = 0;
    for (i=0;text[i] != '\0';i++)
    {
        for (p=0;p<26;p++)
        {
            if (text[i] == az1[p])
            // if ((text[i] = az1[p]) || (text[i] = az2[p]))
                letters++;
            if (text[i] == az2[p])
                letters++;
        }
    }
    // printf("\nLetters: %i\n", letters);
    return letters;
}


//------------------------------------------------------------------------------------
// (4) Function finds last occurrence of an array of given nonsentence words in given text
// NonSentence Words means words that may mistakenly missmatched as the end of sentence
// because of comma at the end of the word (i.e. Mr., Mrs. etc.)
int nonsentense_calc(void)
{
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
        for(l=0; l<text_length - words_array_length[m]; l++)
        {
            found = 0;
            // Match word at current position
            for(j=0; j<words_array_length[m]; j++)
            {
                // found = 0;
                // Count nonsentence if word matched in the text
                if (text[l + j] == words_array[m][j])
                    found  = found + 1;
                    // printf("[%i;%i] Letters for %lu found %d\n", l, j, words_array_length[m], found);
                    if (found == words_array_length[m])
                        nonsentence++;
            }
        }
    }
    return nonsentence;
}

//---------------------------------------------------------
// (5) Function for quantity of sentences by ./!/? +space+1
int sentences_calc(void)
{
    char signs[3] = ".!?";
    sentences = 0;
    for (i = 0; text[i] != '\0'; i++)
    {
        for (m=0; m<3; m++)
        {
            if (text[i] == signs[m] && text[i+1] == ' ')
            sentences++;
        }
    }
    sentences++;

    // NonSentences' exclude Words with comma Mr./Mrs.
    nonsentence = nonsentense_calc();

    // printf("NonSentences: %d\n", nonsentence);
    sentences -= nonsentence;
    // printf("Sentences: %d\n", sentences);
    return sentences;
}

//---------------------------------------------------------
// (6) Function for Coleman-Liau Index Grade index = 0.0588 * L - 0.296 * S - 15.8
int grade(void)
{
    // int letters, words;
    int index = 0;
    index = 5.88 * letters / words - 29.6 * sentences / words - 15.8;
    // printf("%d = 5.88 * %d / %.2d - 29.6 * %d / %d - 15.8 \n", index, letters, words, sentences, words);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    if (index >=1 && index <16)
    {
        printf("Grade %i\n", index);
    }
return index;
}
//---------------------------------------------------------