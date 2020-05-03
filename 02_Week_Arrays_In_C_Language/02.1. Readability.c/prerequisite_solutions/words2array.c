// C program to store, count, detect lengths of words in an array

#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main()
{
	// Enter nonsentence words into array
	// (with space added for further code applying reasons in file findwordintext.c)
	char words_array[][10] = { "Mr. ", "Mrs. ", "MR. ", "MRS. "};

	// Count the quantity of words in array
	int words_array_count = sizeof(words_array) / 10;
	printf("Elements in the array: %i\n", words_array_count);

	// Detect the length of words in words_array and put lengths into new array
	int k = 0;
	long words_array_length[words_array_count];
	for (k=0; k<words_array_count; k++)
	{
		words_array_length[k] = strlen(words_array[k]);
		printf("Length of %i word %s in array is %lu letters\n", k, words_array[k], words_array_length[k]);
	}
}