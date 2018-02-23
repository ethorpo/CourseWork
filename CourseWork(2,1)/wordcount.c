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
	int wrd = 0;
	char* space = " ";
	char words[10000][50];
	int  count[10000] = { 0 };
	char word[50];

	//inputing

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

	//stdinput

	if (strcmp(inputFile, "in") != 0)
	{
		fileIn = fopen(inputFile, "r");
		while ((ch = getc(fileIn)) != EOF)
		{
			chArray[charCount] = ch;
			charCount++;
		}
	}
	else
	{
		printf("Enter text: ");
		gets(chArray);
	}

	//capitalisation

	if (caseSense)
	{
		for (int i = 0; i < sizeof(chArray); i++)
		{
			chArray[i] = tolower(chArray[i]);
		}
	}

	//working file

	file = fopen("working.txt", "w");
	fputs(chArray, file);
	fputs(space, file);
	fclose(file);
	file = fopen("working.txt", "r");

	//sorting

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
			for (int i = 0; i < wrd; i++)
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
				strcpy(words[wrd], word);
				count[wrd++] = 1;
			}
			wordLength = 0;
		}
	}

	//outputing

	if (strcmp(outputFile, "out") != 0)
	{
		fileOut = fopen(outputFile, "w");
		for (int i = 0; i < wrd; i++)
		{
			fprintf(fileOut, "%s:%d\n", words[i], count[i]);
			totalWords = totalWords + count[i];
		}		
		fprintf(fileOut, "Total Words: %d", totalWords);
	}
	else
	{
		for (int i = 0; i < wrd; i++)
		{
			printf("%s:%d\n", words[i], count[i]);
			totalWords = totalWords + count[i];
		}
		printf("Total Words: %d", totalWords);
	}
	return 0;
}