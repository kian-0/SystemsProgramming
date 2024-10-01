/*
 * Author: Kian Aliwalas
 * Course: Systems Programming
 *
 * Instructor: Scott Piersall
 */
#include "headers.h"

#define DEBUG

int main(int argc, char *argv[]) {
    //Starts up file
    FILE *file;
    char line[1024];
    char symbol[32];
    char opcode[32];
    char operand[32];
        int linepos = 0;

    if (argc != 2) {
        printf("Usage: %s <filename>. - where file name is a SIC Assembly file\n", argv[0]);
        return 0;
    }

    file = fopen(argv[1], "r"); //Opens file

    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 0;
    }

    while (fgets(line, 1024, file) != NULL) {
        linepos++;

        printf("Reading: %s", line);

        //Checks beginning of line for # (a comment)
        if (line[0] == 35)
        {
            printf("%d Comment line - Skipping\n", linepos);
            continue;
        } // end comment if
        
        //Checks to see if it is an empty line and ends the program
        if(strlen(line) <= 2) {
            printf("Error: Empty line%d\n", linepos);
            fclose(file);
            return 0;
        }//end strlen if

        //Splits the line into core parts
        sscanf(line, "%s %s %s", symbol, opcode, operand);

        printf("Symbol:%s\n Opcode:%s\n Operand:%s\n", symbol, opcode, operand);

    }//end fgets while loop

    fclose(file); //Closes file
}