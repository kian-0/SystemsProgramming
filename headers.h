#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Symbol 
{
    char Name[7];
    int Address;
    int LineNumber;
    struct Symbol *Next;

} ;

typedef struct Symbol SYMBOL;

typedef struct Symbol* SymbolList;

void PrintSymbolTable(SymbolList table);
