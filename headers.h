#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char Name[7];
    int Address;
    int LineNumber;
    struct Symbol *Next;

} Symbol;

typedef Symbol* SymbolList;
