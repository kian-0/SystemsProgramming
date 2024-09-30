/*
 * Author: Kian Aliwalas
 * Course: Systems Programming
 *
 * Instructor: Scott Piersall
 */
#include "headers.h"

int main(int argc, char *argv[]) {
    //Starts up file
    FILE *file;
    char line[1024];
    char *token;

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

        printf("Reading: %s", line);

        if (line[0] == 35)
        {
            printf("Comment line - Skipping\n");
            continue;
        } // end comment if
        
        if(strlen(line) <= 2) {
            printf("Error: Empty line\n");
            fclose(file);
            return 0;
        }//end strlen if

        while (token - strtok(line, " ")) {
            printf("\tToken: %s\n", token);
            token = strtok(NULL, " \t\n");
        }

    }//end fgets while loop

    fclose(file); //Closes file
}
