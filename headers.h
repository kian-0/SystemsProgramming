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

void PrintSymbolTable(SymbolList table);

int IsInSymbolTable(SymbolList table, char Test[7]);

void InsertSymbol(SymbolList *table, char Name[7], int Addr, int LineNum);

void DeleteList(SymbolList table);

void Instruction();

void GenerateObjectFile(char filename[32]);