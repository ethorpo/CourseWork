#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cmpfunc (const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}

enum { MAX_WORDS = 1000, MAX_WORD_LEN = 32 };

int main(int argc, char*argv[])
{
    char words[MAX_WORDS][MAX_WORD_LEN];
    int  count[MAX_WORDS] = { 0 };
    int w = 0;
    char word[MAX_WORD_LEN];
    int c;
    int l = 0;
	int totalWords = 0;
	FILE *fileIn;
	FILE *fileOut;
	char* inputFile = "in";
	char* outputFile = "out";
	char ch[256];
	int comWord = 0;

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

		while ((c = getc(fileIn)) != EOF)
		{
			if (isalpha(c))
			{
				word[l++] = c;
			}
			else if (l > 0)
			{
				word[l] = '\0';
				int found = 0;
				for (int i = 0; i < w; i++)
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
					strcpy(words[w], word);
					count[w++] = 1;
				}
				l = 0;
			}
		}

	}
	else
	{
		printf("Enter text: ");
		gets(ch);

		for (int i = 0; i < sizeof(ch); i++)
		{

			c = ch[i];
			
			if (isalpha(c))
			{
				word[l++] = c;
			}
			else if (l > 0)
			{
				word[l] = '\0';
				int found = 0;
				for (int i = 0; i < w; i++)
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
					strcpy(words[w], word);
					count[w++] = 1;
				}
				l = 0;
			}
			
		}

	}

	if (strcmp(outputFile, "out") != 0)
	{
		fileOut = fopen(outputFile, "w");
		for (int i = 0; i < w; i++)
		{
			totalWords++;
			fprintf(fileOut, "%s:%d\n", words[i], count[i]);
		}
		fprintf(fileOut, "Total Words: %d", totalWords);
	}
	else
	{
		for (int i = 0; i < w; i++)
		{
			totalWords++;
			printf("%s:%d\n", words[i], count[i]);
		}
		printf("Total Words: %d", totalWords);
	}

	//qsort(count, w, sizeof(int *), cmpfunc);

    
    return 0;
}