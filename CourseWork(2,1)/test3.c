#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int cmpfunc (const void * a, const void * b)
{
	return (*(int*)b - *(int*)a);
}

enum { MAX_WORDS = 1000, MAX_WORD_LEN = 32 };

int main(void)
{
    char words[MAX_WORDS][MAX_WORD_LEN];
    int  count[MAX_WORDS] = { 0 };
    int w = 0;
    char word[MAX_WORD_LEN];
    int c;
    int l = 0;
	int totalWords = 0;

	FILE *fileIn;
	fileIn = fopen("input.txt", "r");

	FILE *fileOut;
	fileOut = fopen("output.txt", "w");

    while ((c = getc(fileIn)) != EOF)
    {
        if (isalpha(c))
        {
           if (l < MAX_WORD_LEN - 1)
               word[l++] = c;
            else
            {
               // fprintf(stderr, "Word too long: %*s%c...\n", l, word, c);
                break;
            } 
        }
        else if (l > 0)
        {
            word[l] = '\0';
  //          printf( "Found word <<%s>>\n", word);
            assert(strlen(word) < MAX_WORD_LEN);
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
                if (w >= MAX_WORDS)
                {
                  //  fprintf(stderr, "Too many distinct words (%s)\n", word);
                    break;
                }
                strcpy(words[w], word);
                count[w++] = 1;
            }
            l = 0;
        }
    }

	qsort(count, w, sizeof(int *), cmpfunc);

    for (int i = 0; i < w; i++)
		{
		totalWords++;
        fprintf(fileOut, "%s:%3d\n", words[i], count[i]);
		}
		fprintf(fileOut, "Total Words: %d", totalWords);
    return 0;
}