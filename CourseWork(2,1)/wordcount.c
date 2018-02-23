/*
Author: Edwin John Thorpe 40316673
Date of Modification: 23/01/18
Purpose of Program: To output all unique words and the amount
of times they occur with a total word count from a file. 
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char*argv[])
{
	bool caseSense = false;
	char* inputFile = "in";
	char* outputFile = "out";
	int totalWords = 0;
	FILE *file;
	FILE *fileIn;
	FILE *fileOut;
	char ch;
	char chArray[10000];
	int charCount = 0;
	int wordLength = 0;
	int wordChar = 0;
	char* space = " ";
	char words[10000][50];
	int  count[10000] = { 0 };
	char word[50];

	/*
	Inputing,
	Reading stdin for arguments 
	and locating files if called
	*/

	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			inputFile = argv[i + 1];
			i++;
		}
		if (strcmp(argv[i], "-o") == 0)
		{
			outputFile = argv[i + 1];
			i++;
		}
		if (strcmp(argv[i], "-c") == 0)
		{
			caseSense = true;
		}
	}

	/*
	stdinput,
	Importing the text from file or stdin
	*/

	if (strcmp(inputFile, "in") != 0)
	{
		fileIn = fopen(inputFile, "r");
		while ((ch = getc(fileIn)) != EOF)
		{
			chArray[charCount] = ch;
			charCount++;
		}
		fclose(fileIn);
	}
	else
	{
		printf("Enter text: ");
		gets(chArray);
	}

	/*
	Capitalisation,
	Turns all upper case to lower case if -c arg is present
	*/

	if (caseSense)
	{
		for (int i = 0; i < sizeof(chArray); i++)
		{
			chArray[i] = tolower(chArray[i]);
		}
	}

	/*
	Working file
	Create a file to edit the input text
	*/

	file = fopen("working.txt", "w");
	fputs(chArray, file);
	fputs(space, file);
	fclose(file);
	file = fopen("working.txt", "r");

	/*
	Sorting
	Sort the text into words and recored each
	individual work and its count
	*/

	while ((ch = getc(file)) != EOF)
	{
		if (isalpha(ch))
		{
			word[wordLength++] = ch;
		}
		else if (wordLength > 0)
		{
			word[wordLength] = '\0';
			int found = 0;
			for (int i = 0; i < wordChar; i++)
			{
				if (strcmp(word, words[i]) == 0)
				{
					count[i]++;
					found = 1;
					break;
				}
			}
			if (!found)
			{
				strcpy(words[wordChar], word);
				count[wordChar++] = 1;
			}
			wordLength = 0;
		}
	}

	/*
	Outputing
	Output the sorted text to either a file or 
	stdout depending if an output file has been given
	*/

	if (strcmp(outputFile, "out") != 0)
	{
		fileOut = fopen(outputFile, "w");
		for (int i = 0; i < wordChar; i++)
		{
			fprintf(fileOut, "%s:%d\n", words[i], count[i]);
			totalWords = totalWords + count[i];
		}		
		fprintf(fileOut, "Total Words: %d", totalWords);
		fclose(fileOut);
	}
	else
	{
		for (int i = 0; i < wordChar; i++)
		{
			printf("%s:%d\n", words[i], count[i]);
			totalWords = totalWords + count[i];
		}
		printf("Total Words: %d", totalWords);
	}
	fclose(file);
	return 0;
}