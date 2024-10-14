#include "headers.h"

void PrintSymbolTable(SymbolList table)
{
    SymbolList temp = table;

    if (temp == NULL)
    {
        printf("Symbol table is empty.\n");
        return;
    }

    printf("Symbol Table:\n");
    while (temp != NULL)
    {
        printf("%s\t%x\n", temp->Name, temp->Address);
        temp = temp->Next;
    }
}
