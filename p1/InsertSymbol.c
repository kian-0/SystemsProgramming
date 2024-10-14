#include "headers.h"

void InsertSymbol(SymbolList *table, char Name[7], int Addr, int LineNum)
{

	struct Symbol *new = malloc(sizeof(struct Symbol));
	memset(new, '\0', sizeof(struct Symbol));

	new->Address = Addr;
	new->LineNumber = LineNum;
	strcpy(new->Name, Name);
	new->Next = NULL; // New symbol will be the last, so Next is NULL

	// If the list is empty, insert as the first element
	if (*table == NULL)
	{
		*table = new;
	}
	else
	{
		// Traverse to the end of the list
		struct Symbol *temp = *table;
		while (temp->Next != NULL)
		{
			temp = temp->Next;
		}
		temp->Next = new; // Link the new symbol at the end
	}
	// printf("Symbol inserted: %s at address %x\n", Name, Addr);
}
