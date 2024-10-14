#include "headers.h"

int IsInSymbolTable(SymbolList table, char Test[7])
{
    SymbolList temp = table;

    while (temp != NULL)
    {
        if (!strcmp(temp->Name, Test))
        {
            // printf("Symbol found\n");
            return 1;
        }
        temp = temp->Next;
    }

    return 0;
}