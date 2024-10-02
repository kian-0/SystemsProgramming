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
    int lineNum = 0;
    int address = 0;
    int numByte = 0;
    SymbolList table = {NULL};

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
        lineNum++;

        // Displays read line
        // printf("%d Reading: %s", lineNum, line);

        // Checks beginning of line for # (a comment)
        if (line[0] == 35)
        {
            // printf("Line %d Comment line - Skipping\n", lineNum);
            continue;
        } // end comment if

        // Checks to see if it is an empty line and ends the program
        if (strlen(line) <= 2)
        {
            printf("Line %d Empty line\n", lineNum);
            fclose(file);
            return 0;
        } // end strlen if

        // Splits the line into core parts
        if (isalpha(line[0]) != 0)
        { // If there is a symbol
            sscanf(line, "%s %s %s", symbol, opcode, operand);
            // printf("Symbol:%s\nOpcode:%s\nOperand:%s\n\n", symbol, opcode, operand);

            // Checks if the symbol is not the same as a directive
            if (strcmp(symbol, "START") == 0 || strcmp(symbol, "END") == 0 || strcmp(symbol, "BYTE") == 0 || strcmp(symbol, "WORD") == 0 || strcmp(symbol, "RESB") == 0 || strcmp(symbol, "RESW") == 0 || strcmp(symbol, "RESR") == 0 || strcmp(symbol, "EXPORTS") == 0)
            {
                printf("Line %d Symbol %s is not a valid name\n", lineNum, symbol);
                return 0;
            }

            // Opcode Handler and symbol inserter
            if (strcmp(opcode, "START") == 0) // Start of SIC
            {
                sscanf(operand, "%x", &address);                // Sets the starting address
                address -= 3;
                InsertSymbol(&table, symbol, address, lineNum); // Inserts symbol
            }
            else if (strcmp(opcode, "RESW") == 0) // Reserve the indicated number of words for a data area.
            { 
                sscanf(operand, "%d", &numByte);
                address += 3 * numByte; //3 Bytes per word 
                printf("%x \n", address);
            }
            else if (strcmp(opcode, "RESB") == 0)
            {
                sscanf(operand, "%d", &numByte);
                //address += numByte; // Reserves x bytes
                printf("%x \n", address);
                
            }
            else if (strcmp(opcode, "WORD") == 0)
            {
                address += 3;

            }
            else if (strcmp(opcode, "BYTE") == 0)
            {
                sscanf(operand, "%d", &numByte);
                printf("%x \n", address);

            }
            else if (strcmp(opcode, "END") == 0)
            {
                return 0;

            }
            else
            { // If there is no special cases/instructions it defaults and assumes it is a regular instruction
                address += 3; // Advances addresses by 3

            }

            // Checks to see if it is in the symbol table
            if (!IsInSymbolTable(table, symbol))
            {
                InsertSymbol(&table, symbol, address, lineNum);
            }
            else
            {
                printf("Line %d Duplicate Symbol found '%s'\n", lineNum, symbol);
                return 0;
            }

        } // end isalpha if
        else
        { // If there is no symbols
            sscanf(line, "%s %s", opcode, operand);
            // printf("Opcode:%s\nOperand:%s\n\n", opcode, operand);
            address += 3; // Advances addresses by 3

        } // end else

        // Clears all the arrays in the event the following instructions do not have anything in that position
        memset(symbol, '\0', sizeof(symbol));
        memset(opcode, '\0', sizeof(opcode));
        memset(operand, '\0', sizeof(operand));

    } // end fgets while loop

    PrintSymbolTable(table);

    fclose(file); // Closes file
}
