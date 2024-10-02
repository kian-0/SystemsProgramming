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
    // Starts up file
    FILE *file;
    char line[1024];
    // Need to check validity of char size below
    char symbol[7];
    char opcode[32];
    char operand[32];
    int linepos = 0;
    int address;
    // Symbol starts
    SYMBOL current;
    SYMBOL prev;
    SymbolList table;

    // Checks if there is the correct amount of arguments
    if (argc != 2)
    {
        printf("Usage: %s <filename>. - where file name is a SIC Assembly file\n", argv[0]);
        return 0;
    } // end arg if

    file = fopen(argv[1], "r"); // Opens file

    // If file doesn't exist
    if (file == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 0;
    } // end fill if

    // Loops thru file and reads each line
    while (fgets(line, 1024, file) != NULL)
    {
        linepos++;

        // Displays read line
        printf("%d Reading: %s", linepos, line);

        // Checks beginning of line for # (a comment)
        if (line[0] == 35)
        {
            printf("%d Comment line - Skipping\n", linepos);
            continue;
        } // end comment if

        // Checks to see if it is an empty line and ends the program
        if (strlen(line) <= 2)
        {
            printf("Error: Empty line %d\n", linepos);
            fclose(file);
            return 0;
        } // end strlen if

        // Splits the line into core parts
        if (isalpha(line[0]) != 0)
        { // If there is a symbol
            sscanf(line, "%s %s %s", symbol, opcode, operand);
#ifdef DEBUG
            printf("Symbol:%s\nOpcode:%s\nOperand:%s\n\n", symbol, opcode, operand);
#endif
            // Checks to see if symbol is start
            if (strcmp(symbol, "START") == 0)
            {
                sscanf(operand, "%x", address); // Sets the starting address
                SYMBOL current = {symbol, address, linepos, NULL};
                table = &current;
                prev = current;
            }
            else
            {
                SYMBOL current = {symbol, address, linepos, NULL};
                prev.Next = &current;
                prev = current;
            }

        } // end isalpha if
        else
        { // If there is no symbol+
            sscanf(line, "%s %s", opcode, operand);
#ifdef DEBUG
            printf("Opcode:%s\nOperand:%s\n\n", opcode, operand);
#endif

        } // end else

        // Clears all the arrays in the event the following instructions do not have anything in that position
        memset(symbol, '\0', sizeof(symbol));
        memset(opcode, '\0', sizeof(opcode));
        memset(operand, '\0', sizeof(operand));

    } // end fgets while loop

    PrintSymbolTable(table);

    fclose(file); // Closes file
}