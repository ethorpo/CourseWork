#include <stdio.h>

int main(int argc, char **argv)
{
	#ifdef DEBUG
		printf("In debugmode\n");
	#elif RELEASE
		printf("In release mode\n");
	#else
		printf("What mode am I in?\n");
	#endif
		return 0;
}