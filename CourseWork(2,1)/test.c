#include <stdio.h>
#include <stdlib.h>

void fatal(char *msg) {
    printf("%s\n", msg);
    exit (1);
}

int main(int argc, char*argv[])
{
    int col1, col2;
    FILE *fp;
    char ch[256];

    if(argc < 4)
        fatal("Need three arguments");

    if (sscanf(argv[2], "%d", &col1) != 1)
        fatal("Argument 1 error");

    if (sscanf(argv[3], "%d", &col2) != 1)
        fatal("Argument 2 error");

    printf("Read columns %d and %d from file %s\n", col1, col2, argv[1]);
    if ((fp = fopen(argv[1], "r")) == NULL)
        fatal("Unable to open file");

    // process the file
    while (fgets(ch, 256, fp) != NULL) {
        printf("%s", ch);
    }
    fclose(fp);
    return 0;
}