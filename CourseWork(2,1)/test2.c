#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{

    FILE *fpIn;
	FILE *fpOut;
    char ch[256];
	char comLine[2];
	char arg[256];
	const char *in[2];
	in[0] = "-";
	in[1] = "i";
	const char *out[2];
	out[0] = "-";
	out[1] = "o";
	int inYes;
	int outYes;
	int inTrue = 0;
	int outTrue = 0;

	for (int i = 1; i < 5; i++)
	{

		arg[i] = sscanf(argv[i]);


		inYes = int strcmp((sscanf(argv[i])), (comLine));
		outYes = int strcmp((sscanf(argv[i])), (comLine));

		if (inYes == 0)
		{
			fpIn = fopen(argv[i + 1], "r");
			inTrue = 1;
		}

		if (outYes == 0)
		{
			fpOut = fopen(argv[i + 1], "w");
			outTrue = 1;
		}
	}

	if (inTrue == 0)
	{
		printf ("Enter text: ");
		gets(ch);
	}

	if (outTrue == 0)
	{
	printf ("%s", ch);
	}

    return 0;
}