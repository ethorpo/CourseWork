#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char*argv[])
{

	FILE *fileIn;
	FILE *fileOut;
	char* inputFile = "in";
	char* outputFile = "out";
    char ch[256];

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
	}

	if (strcmp(inputFile, "in") != 0)
	{
		fileIn = fopen(inputFile, "r");
		//
	}
	else
	{
		printf("Enter text: ");
		gets(ch);
	}

	if (strcmp(outputFile, "out") != 0)
	{	
		fileOut = fopen(outputFile, "w");
		fprintf(fileOut, "%s", ch);
	}	
	else
	{
		printf("%s", ch);
	}

    return 0;
}