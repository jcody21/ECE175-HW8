#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

// Author: John Cody
// Date: 03/25/2018
// Program Description: This program reads words from a file, tests if they are palindromes, and prints the ones that are to a file. 

int main(void) {

	int j = 0, length = 0; // Setting up some loop variables

	char word[15];         // Setting up the forward version of word
	char drow[15];         // Setting up the backward version of word

	FILE *input = fopen("input.txt", "r");         // Creating file pointers and setting them equal to the appropriate file read types
	FILE *output = fopen("palindromes.txt", "w"); 
	
	if (input == NULL) {    // Checking to make sure that the file setup worked properly
		printf("The file input.txt could not be found.\n");
		return -1;
	}
	if (output == NULL) {   // Checking to make sure that the file setup worked properly
		printf("The file palindromes.txt could not be found.\n");
		return -1;
	}

	while (fgets(word, 15, input) != NULL) {   // This loops through the input file to sequentially test every word in the file

		length = strlen(word);  // Checks the lenght of the word
		word[length - 1] = '\0';  // Sets the last character of the word to the NULL character as the previous last character would be the newline character
		if (word[length - 2] == ' ') { //Checks to make sure that there are no spaces that were accidentally addded that would mess up the palindrome test (occurs for word testset)
			word[length - 2] = '\0'; // Change the space to a NULL character
		}
		length = strlen(word);    // Finds the new lenght of the word
		for (j = 0; j < length; j++) {
			drow[length - j - 1] = word[j];  // looping through and setting drow to the reverse of word
		}
		drow[j] = '\0';  // Setting the last character of drow to the NULL character

		if (strcmp(word, drow) == 0) {  // Testing to see if the forward and backward versions of the word are the same
			fprintf(output, "%s\n", word);   // If yes, the word gets printed to the palindromes/output file
		}                                    // else, nothing happens and the program goes back to the input file and gets the next word
	}

	fclose(input);   // Closing the files
	fclose(output);

	return 0;
}