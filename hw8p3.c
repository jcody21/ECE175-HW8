#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// Author: John Cody
// Date: 03/25/2018
// Program Description: This program takes an file and a target string and finds when the target string appears in the file and outputs that line. 

int isPresent(char line[100], char search[25]);  // checks to see if the search string is present in the line string, if yes it returns 1 otherwise 0

int main(void) {

	int counter = 1;     // counter for the line-target instances
	char string[25];     // char array that will be the file name as read from the user and the target string also from the user
	char row[100];       // array that will hold the lines from the file when they are read

	printf("Enter the name of the file you want to search: ");  // Prompts the user for the file name
	scanf(" %s", string);  // scans for the file name 
	
	FILE* file = fopen(string, "r");  // uses the given file name to try and open a file

	if (file == NULL) {   // checks to make sure that the file opened properly 
		printf("File %s could not be found and opened.\n", string);
		return -1;
	}
	
	printf("Enter the target string: ");  // prompts the user for the target string to be found in the file
	scanf(" %s", string);   // scanning for the given target string
	printf("\n");

	while (fgets(row, 100, file) != NULL) { // loops through the file trying to find the target string
		if (isPresent(row, string)) {       // calling the "isPresent" function that checks if one string is present in another 
			printf("%d. %s", counter, row); // if the target string is present the line is printed with the counter number out front
			counter++;                      // the counter is incremented so that it is prepared for the next instance of when the target string is present
		}
	}

	printf("\n");  // formatting
	fclose(file);  // closing the file
	return 0;
}

int isPresent (char line[100], char search[25]) {  // checks to see if the search string is present in the line string, if yes it returns 1 otherwise 0
	int j = 0, i = 0;                      // Setting up some loop variables 
	int line_length = strlen(line);        // Setting up the lenght variables
	int search_length = strlen(search);

	for (j = 0; j < line_length; j++) {   // Looping through the entire line array
		i = 0;                            // resetting the i value for returning attempts
		while ((line[j + i] == search[i]) && (i < search_length)) { // Looping through the line and search arrays while they equal each other
			i++;  // incrementing the i value to check the two arrays at the next digit
		}
		if (i == search_length) { // if the loop finished because the end of the search array had been reached, then there was a match!
			return 1;  // return this result 
		}
	}
	return 0; // if after checking ther entire line array there was no match, return this failure
}