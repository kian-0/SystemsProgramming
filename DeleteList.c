#include <headers.h>

void DeleteList(SymbolList table)
{
    if (table == NULL)
    {
        return;
    }
    else
    {
        DeleteList(table->Next);
        free(table);
    }
}