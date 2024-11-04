#include "headers.h"

void InsertMRecord(mRecordList *mtable, int Star, int Leng, char Fla, char Sym[7])
{

    struct mRecord *new = malloc(sizeof(struct mRecord));
    memset(new, '\0', sizeof(struct mRecord));

    new->Start = Star;
    new->Length = Leng;
    new->Flag = Fla;
    strcpy(new->Symbol, Sym);
    new->Next = NULL; // New symbol will be the last, so Next is NULL

    // If the list is empty, insert as the first element
    if (*mtable == NULL)
    {
        *mtable = new;
    }
    else
    {
        // Traverse to the end of the list
        struct mRecord *temp = *mtable;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = new; // Link the new symbol at the end
    }
    // printf("Symbol inserted: %s at address %x\n", Name, Addr);
}
