#include <stdlib.h>
#include <stdio.h>
#include "generate.h"
#include "sort.h"
#include "search.h"

#define NUM_INTERGERS 65536

int main(int argc, char **argv)
{
	int data[NUM_INTERGERS];
	generate(NUM_INTERGERS, data);
	printf("\nUnsorted\n");
	for (int i = 0; i < 20; i++)
		printf("%d\n", data[i]);
	sort(NUM_INTERGERS, data);
	printf("\nSorted\n");
	for (int i = 0; i < 20; i++)
		printf("%d\n", data[i]);
	return 0;
}