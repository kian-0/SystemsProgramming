/*
 * Author: Kian Aliwalas
 * Course: Systems Programming
 *
 * Instructor: Scott Piersall
 */
#include "headers.h"

#define DEBUG

int main(int argc, char *argv[])
{
    // Sets up filename to send to Pass1
    char filename[32];

    //printf("%d %s %s %s\n", argc, argv[0], argv[1], argv[2]);//De Bugging

    // Checks if there is the correct amount of arguments
    if (argc < 2 || argc > 3)
    {
        printf("Usage: %s <filename>. - where file name is a SIC Assembly file -<options>\n./project2 --o for options\n", argv[0]);
        return 0;
    } // end argc (2 <= x <= 3) if

    sprintf(filename, "%s", argv[1]);//Sets filename

    if (strcmp(argv[1], "--o") == 0)
    {
        printf("--pass1only\t Only execute pass1\n");
        exit(1);
    } //end options msg

    // Checks to see if it is only asking for pass1 
    if (argc == 3)
    {
        if (strcmp(argv[2], "--pass1only") == 0)
        {
            PrintSymbolTable(Pass1(filename));
            printf("End of Pass1\n");
        }
        else{
            printf("Not a valid option\n");
        } // end options if branch
    } //end argc == 3

    // If there is no 3rd argument it runs normally
    if (argc == 2)
    {
        Pass2(Pass1(filename), filename);
    } //end argc == 2 if

    
}
