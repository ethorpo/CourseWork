#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

int main(int argc, char **argv)
{
	int wordCount = 0;

	//open input and output

	FILE *fileIn;
	fileIn = fopen("input.txt", "r");

	FILE *fileOut;
	fileOut = fopen("output.txt", "w");

	//define Array

	char wordArray[100];
	fgets(wordArray, 100, (FILE*)fileIn);

	//scan file

	for (int i = 0; sizeof(wordArray) > i; i++)
	{
		if (isalpha(wordArray[i]))
		{
			wordCount++;
		}
	}
	
	//print to output

	fprintf(fileOut, "%s\t", wordArray);
	fprintf(fileOut, "Word Count: %d", wordCount);

}

//for file 2
/*
const char s[2] = " ";
char *token;

token = strtok(str, s);

while (token != NULL)
{
printf("%s\n", token);
token = strtok(NULL, s);
}
*/