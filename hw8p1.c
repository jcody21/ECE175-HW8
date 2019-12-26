#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Author: John Cody
// Date: 03/25/2018
// Program Description: This program flips all of the letters in a word in a setence, but keeps the order of the word in the setence.  

int main(void) {
	int i = 0, j = 0, length = 0;   // Setting up some loop variables
	char again = 'y';  // Letter that will determine if the program will loop again. 
	char str[100];	   // Array that will hold the whole setence
	char word[20];	   // Array that will hold the word as read forwards
	char drow[20];     // Array that will hold the word as read backwards

	while (again == 'y') {   // Big while loop that keeps looping until the user doesn't want to keep providing prompts
		printf("Enter a sentence : ");  // Prompts the user to input the setence which words will be flipped
		fgets(str, 100, stdin);         // Scans that input from the line into the str array
		length = strlen(str);           // Read the length of the str array into the lenght variable
		str[length] = ' ';              // Sets the current last spot of the str array to the space character - this is how the program can distinguish the last word
		str[length + 1] = '\0';         // Sets the new last character of the array to the NULL character
		i = 0;                          // Setting i = 0 in case the program has already looped through once and is i != 0

		while ((i < 100) && (str[i] != '\0')) {  // The while loop that goes through the str array to find the words, reverse them, and print them 
			j = 0;   // Resetting j to zero if this part of the code has already been looped through
			while ((str[i] != ' ') && (j < 20) && (str[i] != '\n')) {  // While loop that finds words in the str array and reads them into the word array
				word[j] = str[i];   // Reading the word from the str array to the word array
				i++;   // Incrementing to get to the next part of the word array
				j++;   // Incrementing to get to the next part of the str array
			}

			i++;      // If the previous loop found a word and exited when str[i] = ' ', the spot has to be incremented so that for the next word that loop doesn't get skipped
			word[j] = '\0';  // Ensuring that the word ends with a NULL character
			length = strlen(word);  // Setting the lenght variable to the lenght of the word array
			
			for (j = 0; j < length; j++) {    // loops through and reads word into drow backwards
				drow[length - j - 1] = word[j];
			}
			
			drow[j] = '\0';  // Setting the last character of drow to the NULL character
			printf("%s ", drow); // Outputting the word that was found in the setence and then reversed
		}

		printf("\n\nWould you like to do this again? (y/n): ");   // Prompting the user if they want to flip words again
		scanf(" %c", &again);  // Scanning for the users input
		getchar();             // This gets the newline character from stdin and discards it to prevent the fgets function from closing immediately and not waiting to take input
		
		while ((again != 'y') && (again != 'n')) { // This is in case the user is a pos and decides to not enter one of the provided options
			printf("That input was not one of the options. Please try again. \n");
			printf("\nWould you like to do this again? (y/n): ");  // Prompting the user for some fresh input
			scanf(" %c", &again);   // Scanning for that input
			getchar();   // Discarding the newline character again
		}
		
		printf("\n");  // formatting 
	}
	return 0;
}