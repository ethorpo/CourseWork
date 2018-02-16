#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char** str_split(char* a_str, const char a_delim)
{
	char** result = 0;
	size_t count = 0;
	char* tmp = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	/* Count how many elements will be extracted. */
	while (*tmp)
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	/* Add space for trailing token. */
	count += last_comma < (a_str + strlen(a_str) - 1);

	/* Add space for terminating null string so caller
	knows where the list of returned strings ends. */
	count++;

	result = malloc(sizeof(char*) * count);

	if (result)
	{
		size_t idx = 0;
		char* token = strtok(a_str, delim);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

int main()
{
	int lines = 0;
	char ch;
	int wordcount = 0;
	int charcount = 0;

	FILE *fileIn;
	fileIn = fopen("input.txt", "r");

	FILE *fileOut;
	fileOut = fopen("output.txt", "w");

	char wordArray[100];
	fgets(wordArray, 100, (FILE*)fileIn);
	char** tokens;

	tokens = str_split(wordArray, ' ');

	if (tokens)
	{
		int i;
		for (i = 0; *(tokens + i); i++)
		{
			fprintf(fileOut, "%s\n", *(tokens + i));
			free(*(tokens + i));
			lines++;
		}
		free(tokens);
	}
		//Repeat until End Of File character is reached.	
		while ((ch = getc(fileIn)) != EOF) {

			if (ch != ' ' && ch != '\n') { ++charcount; }
			// Increment word count if new line or space character
			if (ch == ' ' || ch == '\n') { ++wordcount; }

		}

		if (charcount > 0) {

			++wordcount;
		}

		fprintf(fileOut, "%d\n", wordcount);

	return 0;
}