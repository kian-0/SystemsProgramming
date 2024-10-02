#include "headers.h"

void PrintSymbolTable(SymbolList table)
{
    SymbolList temp;
    temp = table;

    while (temp != NULL)
    {
        printf("%s\t%x\n", temp->Name, temp->Address);
        temp = temp->Next;
    }
}