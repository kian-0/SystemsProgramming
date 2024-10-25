#include "headers.h"

void GenerateObjectFile(char filename[32])
{
    // starts output
    FILE *output = fopen(filename, "a");

    if (output == NULL)
    {
        printf("Error opening the file %s\n", filename);
    }


    fclose(output);
}