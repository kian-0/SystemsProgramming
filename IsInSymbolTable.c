#include "headers.h"

int IsInSymbolTable(SymbolList table, char Test[7])
{
    SymbolList temp = table;

    while (temp != NULL)
    {
        if (!strcmp(temp->Name, Test))
        {
            // printf("Symbol found\n");
            return temp->Address;
        }
        temp = temp->Next;
    }

    return 0;
}