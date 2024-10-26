#include "headers.h"

void InsertTRecord(tRecordList *rtable, int Star, int Leng, char Cod[60])
{

    struct tRecord *new = malloc(sizeof(struct tRecord));
    memset(new, '\0', sizeof(struct tRecord));

    new->Length = Leng;
    strcpy(new->Code, Cod);
    new->Start = Star;
    new->Next = NULL; // New symbol will be the last, so Next is NULL

    // If the list is empty, insert as the first element
    if (*rtable == NULL)
    {
        *rtable = new;
    }
    else
    {
        // Traverse to the end of the list
        struct tRecord *temp = *rtable;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        temp->Next = new; // Link the new symbol at the end
    }
    // printf("Symbol inserted: %s at address %x\n", Name, Addr);
}
