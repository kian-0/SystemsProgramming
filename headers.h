#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Symbol
{
    char Name[7];
    int Address;
    int LineNumber;
    struct Symbol *Next;
};

typedef struct Symbol SYMBOL;

typedef struct Symbol *SymbolList;

struct tRecord{

    char Start[6];
    char Length[2];
    char Code[60];
    struct tRecord *Next;

};

typedef struct tRecord TRECORD;

typedef struct tRecord *tRecordList;

void PrintSymbolTable(SymbolList table);

int IsInSymbolTable(SymbolList table, char Test[7]);

void InsertSymbol(SymbolList *table, char Name[7], int Addr, int LineNum);

void DeleteList(SymbolList table, tRecordList rtable);

void Pass2(SymbolList table);

void InsertTRecord(tRecordList *rtable, char Start[6], char Length[2], char Code[60]);

void GenerateObjectFile(char filename[32]);