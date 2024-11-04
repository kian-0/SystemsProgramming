#include "headers.h"

void GenerateObjectFile(char filename[32], HRECORD hRecord, tRecordList rtable, mRecordList mtable, ERECORD eRecord)
{
    // starts output
    FILE *output = fopen(filename, "w");

    tRecordList rtemp = rtable;
    mRecordList mtemp = mtable;

    if (output == NULL)
    {
        printf("Error opening the file %s\n", filename);
    }

    // Prints H Record
    fprintf(output, "H%-6s%.6x%.6x\n", hRecord.Name, hRecord.Start, hRecord.Size);

    // Loops thru tRecordList
    while (rtemp != NULL)
    {
        fprintf(output, "T%.6x%.2x%s\n", rtemp->Start, rtemp->Length, rtemp->Code);
        rtemp = rtemp->Next;
    }

    // Loops thru mRecordList
    while (mtemp != NULL)
    {
        fprintf(output,"M%.6x%.2x%c%s\n", mtemp->Start + 1, mtemp->Length, mtemp->Flag, mtemp->Symbol);
        mtemp = mtemp->Next;
    }

    // Print E Record
    fprintf(output, "E%.6x\n", eRecord.Address);

    fclose(output);
}