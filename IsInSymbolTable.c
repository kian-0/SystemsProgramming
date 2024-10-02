#include "headers.h"

int IsInSymbolTable(SymbolList table, char Test[7])
{

    int Result;
    SymbolList temp;
    Result = 0;

    while (temp != NULL)
    {
        if (!strcmp(temp->Name, Test))
        {
            Result = 1;
            break;
        }
        temp = temp->Next;
    }

    return Result;
}