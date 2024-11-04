#include "headers.h"

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

void DeleteTList(tRecordList rtable)
{
    if (rtable == NULL)
    {
        return;
    }
    else
    {
        DeleteTList(rtable->Next);
        free(rtable);
    }
}

void DeleteMList(mRecordList mtable)
{

    if (mtable == NULL)
    {
        return;
    }
    else
    {
        DeleteMList(mtable->Next);
        free(mtable);
    }
}