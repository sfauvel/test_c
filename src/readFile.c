#include <stdio.h>
#include <string.h>
#include "../include/readFile.h"

#define BUFSIZE 256

int
read_file(char *file, char *output) {

    char buffer [BUFSIZE];
    char *p;
    FILE *fp;

    printf("Read: %s\n", file);

    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf ("Error opening file %s\n", file);
        return 1;
    }

    printf ("Start reading\n");

    while(! feof (fp))
    {
        if(fgets (buffer, BUFSIZE, fp) != NULL)
        {
            printf("Read: %s\n", buffer);
            strcpy(output, buffer);

        }
    }

    if (fclose (fp))
    {
        printf("Error closing file\n");
    } else
    {
        printf("File closed\n");
    }
    return 0;
}