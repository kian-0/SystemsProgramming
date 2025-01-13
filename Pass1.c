#include "headers.h"

SymbolList Pass1(char filename[32])
{
    FILE *file;
    char line[1024];
    char symbol[7];
    char opcode[64];
    char operand[64];
    int lineNum = 0;
    int address = -1;
    int numByte = 0;
    int hasStart = 0;
    SymbolList table = NULL;

    file = fopen(filename, "r"); // Opens file

    // If file doesn't exist
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
        return 0;
    } // end fill if

    // Loops thru file and reads each line
    while (fgets(line, 1024, file) != NULL)
    {
        lineNum++;

        // Clears all the arrays in the event the following instructions do not have anything in that position
        memset(symbol, '\0', sizeof(symbol));
        memset(opcode, '\0', sizeof(opcode));
        memset(operand, '\0', sizeof(operand));

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
            printf("Line %d Blank lines detected. Stopping\n", lineNum);
            fclose(file);
            return 0;
        } // end strlen if

        // Splits the line into core parts
        if (isalpha(line[0]) != 0)
        { // If there is a symbol
            sscanf(line, "%s %s %[^\n]s", symbol, opcode, operand);
            // printf("Symbol:%s\nOpcode:%s\nOperand:%s\n\n", symbol, opcode, operand);

            // Checks if the symbol is not the same as a directive
            if (strcmp(symbol, "START") == 0 || strcmp(symbol, "END") == 0 || strcmp(symbol, "BYTE") == 0 || strcmp(symbol, "WORD") == 0 || strcmp(symbol, "RESB") == 0 || strcmp(symbol, "RESW") == 0 || strcmp(symbol, "RESR") == 0 || strcmp(symbol, "EXPORTS") == 0)
            {
                printf("Line %d Symbol %s is not a valid name. Stopping\n", lineNum, symbol);
                exit(1);
            }

            // Checks to see if it is in the symbol table
            if (IsInSymbolTable(table, symbol))
            {
                printf("Line %d Duplicate Symbol found '%s'. Stopping\n", lineNum, symbol);
                exit(1);
            }

            // Checks to see if it passed the memory limit
            if (address > 32768)
            {
                printf("Line %d Exeeding memory capacity. Stopping \n", lineNum);
                exit(1);
            }

            // Opcode Handler and symbol inserter
            if (strcmp(opcode, "START") == 0) // Start of SIC
            {
                sscanf(operand, "%x", &address); // Sets the starting address
                InsertSymbol(&table, symbol, address, lineNum);
                hasStart = 1;
            }
            else if (strcmp(opcode, "RESW") == 0) // Reserve the indicated number of words for a data area.
            {
                sscanf(operand, "%d", &numByte);
                InsertSymbol(&table, symbol, address, lineNum);
                address += 3 * numByte; // 3 Bytes per word
                // printf("RESW %x %d \n", address,numByte);
            }
            else if (strcmp(opcode, "RESB") == 0)
            {
                sscanf(operand, "%d", &numByte);
                InsertSymbol(&table, symbol, address, lineNum);
                address += numByte; // Reserves x bytes
                // printf("RESB %x %d \n", address, numByte);
            }
            else if (strcmp(opcode, "WORD") == 0)
            {
                sscanf(operand, "%d", &numByte);
                InsertSymbol(&table, symbol, address, lineNum);
                if (numByte >= 8388607) // 2^23 -1 Checks to see if it exeeds signed limit for int
                {
                    printf("Line %d Word Constant exeeds 24 bit limit. Stopping\n", lineNum);
                    exit(1);
                }
                address += 3;
            }
            else if (strcmp(opcode, "BYTE") == 0)
            {
                char indicator;
                char hex[32];
                numByte = 0;
                memset(hex, '\0', sizeof(hex));
                sscanf(operand, "%c%s", &indicator, hex);
                switch (indicator)
                {
                case 'X':
                    for (int i = 0; i < strlen(hex); i++)
                    {
                        if (hex[i] == 39)
                        {
                            // printf("Detected %c at %d\n", hex[i], i);
                        }
                        else if (hex[i] >= 48 && hex[i] <= 57)
                        {
                            // printf("Detected number %c at %d\n", hex[i], i);
                            ++numByte;
                        }
                        else if (hex[i] >= 65 && hex[i] <= 70)
                        {
                            // printf("Detected letter %c at %d\n", hex[i], i);
                            ++numByte;
                        }
                        else
                        {
                            printf("Line %d Error at BYTE with %c at %d. Stopping\n", lineNum, hex[i], i);
                            exit(1);
                        }
                    }
                    numByte /= 2;
                    break;

                case 'C':
                    for (int i = 0; i < strlen(operand); i++)
                    {
                        if (operand[i] >= 32 && operand[i] <= 126)
                        {
                            // printf("Detected something %c at %d\n", hex[i], i);
                            ++numByte;
                        }                        
                    }
                    numByte -= 3;
                    break;
                }
                InsertSymbol(&table, symbol, address, lineNum);
                address += numByte;
                memset(operand, '\0', sizeof(operand));
            }
            else if (strcmp(opcode, "END") == 0)
            {
                memset(symbol, '\0', sizeof(symbol));
                memset(opcode, '\0', sizeof(opcode));
                memset(operand, '\0', sizeof(operand));
                // PrintSymbolTable(table); // Marks end of SIC file and prints out symbol table
                if (hasStart == 0)
                {
                    printf("No Start Directive Stopping\n");
                    DeleteList(table);
                    exit(1);
                }
                fclose(file);
                return table;
            }
            else
            { // If there is no special cases/instructions it defaults and assumes it is a regular instruction
                InsertSymbol(&table, symbol, address, lineNum);
                address += 3; // Advances addresses by 3
            }

        } // end isalpha if
        else
        { // If there is no symbols
            sscanf(line, "%s %s", opcode, operand);
            // printf("Opcode:%s\nOperand:%s\n\n", opcode, operand);
            if (isalpha(line[0]) == 0 && isblank(line[0]) == 0)
            {
                printf("Line %d Character %c not valid. Stopping \n", lineNum, line[0]);
                exit(1);
            }
            address += 3; // Advances addresses by 3

        } // end else

        // Clears all the arrays in the event the following instructions do not have anything in that position
        memset(symbol, '\0', sizeof(symbol));
        memset(opcode, '\0', sizeof(opcode));
        memset(operand, '\0', sizeof(operand));
        numByte = 0;

    } // end fgets while loop
    return 0;
}