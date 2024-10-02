#include "headers.h"

void InsertSymbol(SymbolList *table, char Name[7], int Addr, int LineNum)
{

	struct Symbol *new;

	new = malloc(sizeof(struct Symbol));
	memset(new, '\0', sizeof(struct Symbol));

	new->Address = Addr; //
	new->LineNumber = LineNum;
	strcpy(new->Name, Name);
	new->Next = NULL; // Makes last next lead to NULL

	// If the table is empty sets the Symbol to first
	if (*table == NULL)
	{
		*table = new;
	}
	else
	{						   // Otherwise it will go to the end of the list
		SYMBOL *temp = *table; // Takes the current table and set it in temp
		// Goes to the end of the table
		while (temp->Next != NULL) // While temp.Next is not Null
		{
			temp = temp->Next; // go to Next symbol
		}
		temp->Next = new; // Sets new symbol to the end
	}

	// printf("Symbol inserted: %s at address %x\n\n", Name, Addr); //Debugging
}
