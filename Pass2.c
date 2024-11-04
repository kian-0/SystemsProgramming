#include "headers.h"

void Pass2(SymbolList table, char filename[32])
{
    if (table == NULL)
    {
        exit(1);
    }

    // For T Records Hold values untill code is filled then it sends it to the tRecord list
    int Start;
    int Length;
    char Code[60];
    char CodeAdd[60];
    FILE *file;
    tRecordList rtable = NULL;
    mRecordList mtable = NULL;
    HRECORD hRecord;
    ERECORD eRecord;
    memset(Code, '\0', sizeof(Code));

    // Line Reading Vars
    char line[1024];
    char symbol[7];
    char startSym[7];
    char opcode[64];
    char operand[64];
    int lineNum = 0;
    int address = 0;
    int numByte = 0;
    char r1;

    file = fopen(filename, "r");

    // If file doesn't exist
    if (file == NULL)
    {
        printf("Error opening file %s\n", filename);
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

        // Splits the line into core parts
        if (isalpha(line[0]) != 0)
        { // If there is a symbol
            sscanf(line, "%s %s %s", symbol, opcode, operand);
            // printf("Symbol:%s\nOpcode:%s\nOperand:%s\nLine:%d\n\n", symbol, opcode, operand, lineNum);

            // Creates the mRecords (INCORRECTLY) it hard codes the length,flag, and where its being modified
            if (IsInSymbolTable(table, operand))
            {
                // printf("Is in symbol table\n");
                sscanf(CodeAdd, "%x", &address);
                InsertMRecord(&mtable, address, strlen(CodeAdd), '+', startSym);
                memset(CodeAdd, '\0', sizeof(CodeAdd));
            }

            if (strcmp(opcode, "START") == 0) // Start of SIC
            {
                sscanf(operand, "%x", &address); // Gets starting address
                strcpy(startSym, symbol);        // Used for m Records and h record
                strcpy(hRecord.Name, startSym);  // Sets the name of the start record
                hRecord.Start = address;         // Sets starting address
                eRecord.Address = address;
            }
            else if (strcmp(opcode, "RESW") == 0) // Reserve the indicated number of words for a data area.
            {
                sscanf(operand, "%d", &numByte);
                address += 3 * numByte; // 3 Bytes per word
            }
            else if (strcmp(opcode, "RESB") == 0)
            {
                sscanf(operand, "%d", &numByte);
                address += numByte; // Reserves x bytes
            }
            else if (strcmp(opcode, "WORD") == 0)
            {
                sscanf(operand, "%d", &numByte);
                address += 3;
            }
            else if (strcmp(opcode, "BYTE") == 0)
            {
                char indicator;
                char hex[32];
                char temp[32];
                memset(temp, '\0', sizeof(temp));
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
                            temp[strlen(temp)] = hex[i];
                        }
                        else if (hex[i] >= 65 && hex[i] <= 70)
                        {
                            // printf("Detected letter %c at %d\n", hex[i], i);
                            temp[strlen(temp)] = hex[i];
                        }
                        else
                        {
                            printf("Line %d Error at BYTE with %c at %d. Stopping\n", lineNum, hex[i], i);
                        }
                    }
                    // printf("%s\n", temp);
                    sscanf(temp, "%x", &numByte);
                    break;

                case 'C':
                    numByte = strlen(hex) - 2;
                    break;
                }

                address += numByte;
                memset(operand, '\0', sizeof(operand));
            }
            else if (strcmp(opcode, "END") == 0)
            {
                if (IsInSymbolTable(table, operand) == 0)
                {
                    printf("Line %d Symbol %s is not defined. Stopping\n", lineNum, operand);
                    exit(1);
                }

                hRecord.Size = address;
                memset(symbol, '\0', sizeof(symbol));
                memset(opcode, '\0', sizeof(opcode));
                memset(operand, '\0', sizeof(operand));
            }
            else
            { // If there is no special cases/instructions it defaults and assumes it is a regular instruction

                if (IsDirective(opcode) != 0 && IsInSymbolTable(table, operand) == 0 && strcmp(opcode, "RSUB") != 0)
                {
                    printf("Line %d Symbol %s is not defined. Stopping\n", lineNum, operand);
                    exit(1);
                }

                address += 3; // Advances addresses by 3
            }
        }
        else
        {
            // Ensures the reading lines up so that the opcode is not read as a symbol... etc
            sscanf(line, "%s %s", opcode, operand);
            // printf("Symbol:%s\nOpcode:%s\nOperand:%s\nLine:%d\n\n", symbol, opcode, operand, lineNum);

            // Checks to see if the operand contains "," for r1 stuff
            if (strstr(operand, ",") != 0)
            {
                r1 = '\0';                                                          // Clears r1 for new r1
                char temp[64];                                                      // Creates temp
                strcpy(temp, operand);                                              // Copies to temp
                sscanf(strstr(operand, ","), "%*c%c", &r1);                         // Reads the ",X"
                memset(operand, '\0', sizeof(operand));                             // Clears operand
                strncpy(operand, temp, (strlen(temp) - strlen(strstr(temp, ",")))); // Copies string back minus ",X"
                // printf("%s %c\n", operand,r1); //Debugging
                memset(temp, '\0', sizeof(temp)); // Clears temp
            }

            if (IsDirective(opcode) != 0 && IsInSymbolTable(table, operand) == 0 && strcmp(opcode, "RSUB") != 0)
            {
                printf("Line %d Symbol %s is not defined. Stopping\n", lineNum, operand);
                exit(1);
            }

            // Creates the mRecords (INCORRECTLY) it hard codes the length,flag, and where its being modified
            if (IsInSymbolTable(table, operand))
            {
                // printf("Is in symbol table\n");
                InsertMRecord(&mtable, address, 4, '+', startSym);
            }
            address += 3;
        }

        // Below adds t Records
        if (IsDirective(opcode) != 0)
        {
            sprintf(CodeAdd, "%s%.4x", Instruction(opcode), address); // Calculates code is to be added
            if (strstr(CodeAdd, "!!!!missread!!!!"))
            {
                memset(CodeAdd, '\0', sizeof(CodeAdd));
                continue;
            }
            // printf("%s\n%s\n", CodeAdd,line);
        }
        else
        {
            continue;
        }

        // For the very first one
        if (strlen(Code) == 0)
        {
            Start = address + 1;                    // Sets starting address
            strcat(Code, CodeAdd);                  // Adds to code base
            memset(CodeAdd, '\0', sizeof(CodeAdd)); // Clears CodeAdd
        }

        if (strlen(Code) + strlen(CodeAdd) < 60)
        { // If code length is less than 60 would add to the code
            strcat(Code, CodeAdd);                            // Adds to code base
            memset(CodeAdd, '\0', sizeof(CodeAdd));           // Clears CodeAdd
        }
        else
        { // If longer than 60 would insert to the T record list and create a new one
            Length = strlen(Code) / 2;                   // Calculates the length
            InsertTRecord(&rtable, Start, Length, Code); // Insters to tRecord List
            memset(Code, '\0', sizeof(Code));            // Clears Code
            memset(CodeAdd, '\0', sizeof(CodeAdd));      // Clears CodeAdd

            // Starts new one
            strcat(Code, CodeAdd); // Adds to code base
            Start = address + 1;   // Sets new Start address
        }
    }

    Length = strlen(Code) / 2;
    InsertTRecord(&rtable, Start, Length, Code); // adds last parts of t record

    fclose(file);
    char outname[32];
    sprintf(outname, "%s.obj", filename);
    GenerateObjectFile(outname, hRecord, rtable, mtable, eRecord);
    DeleteMList(mtable);
    DeleteTList(rtable);
    printf("End of Pass2\n");
}