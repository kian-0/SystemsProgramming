#include "headers.h"

void Pass2(SymbolList table, char filename[32])
{
    // For T Records Hold values untill code is filled then it sends it to the tRecord list
    int Start;
    int Length;
    char Code[60];
    memset(Code, '\0', sizeof(Code));
    char CodeAdd[60];
    FILE *file;
    tRecordList rtable = NULL;
    mRecordList mtable = NULL;
    HRECORD hRecord;
    ERECORD eRecord;

    // Line Reading Vars
    char line[1024];
    char symbol[7];
    char startSym[7];
    char opcode[64];
    char operand[64];
    int lineNum = 0;
    int address = 0;
    int numByte = 0;

    file = fopen(filename, "r");

    PrintSymbolTable(table);

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
            //printf("Symbol:%s\nOpcode:%s\nOperand:%s\nLine:%d\n\n", symbol, opcode, operand, lineNum);

            // Creates the mRecords (INCORRECTLY) it hard codes the length,flag, and where its being modified
            if (IsInSymbolTable(table, operand))
            {
                //printf("Is in symbol table\n");
                InsertMRecord(&mtable, address, 4, '+', startSym);
            }

            if (strcmp(opcode, "START") == 0) // Start of SIC
            {
                sscanf(operand, "%x", &address); // Gets starting address
                strcpy(startSym, symbol);        // Used for m Records and h record
                strcpy(hRecord.Name, startSym); // Sets the name of the start record
                hRecord.Start = address;        // Sets starting address
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
                //INSERT

                address += numByte;
                memset(operand, '\0', sizeof(operand));
            }
            else if (strcmp(opcode, "END") == 0)
            {
                hRecord.Size = address;
                memset(symbol, '\0', sizeof(symbol));
                memset(opcode, '\0', sizeof(opcode));
                memset(operand, '\0', sizeof(operand));
            }


        }
        else
        {
            // Ensures the reading lines up so that the opcode is not read as a symbol... etc
            sscanf(line, "%s %s", opcode, operand);
            //printf("Symbol:%s\nOpcode:%s\nOperand:%s\nLine:%d\n\n", symbol, opcode, operand, lineNum);

            // Creates the mRecords (INCORRECTLY) it hard codes the length,flag, and where its being modified
            if (IsInSymbolTable(table, operand))
            {
                //printf("Is in symbol table\n");
                InsertMRecord(&mtable, address, 4, '+', startSym);
            }
            address+=3;
        } 


        // Below adds t Records
        sprintf(CodeAdd, "%s%.4x",Instruction(opcode),address);
    
        // InsertTRecord(&rtable, address,0,CodeAdd);

        if(strlen(Code) == 0){
            Start = address + 1;

        }

        if(strlen(Code) + strlen(CodeAdd) < 60){
            strcat(Code, CodeAdd);
        }else{
            Length = strlen(Code)/2;
            strcat(Code, CodeAdd);
            InsertTRecord(&rtable,Start,Length,Code);
            memset(Code, '\0', sizeof(Code));
        }
        // printf("%s\n",Code);
        
    }

    InsertTRecord(&rtable, Start, Length, Code); //adds last parts of t record
    fclose(file);
    char outname[32];
    sprintf(outname, "%s.obj", filename);
    GenerateObjectFile(outname, hRecord, rtable, mtable, eRecord);
    DeleteMList(mtable);
    DeleteTList(rtable);
    printf("End of Pass2\n");
}