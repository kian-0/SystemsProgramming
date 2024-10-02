#include "headers.h"

void InsertSymbol(SymbolList table, char Name[7], int Addr, int LineNum)
{

	struct Symbol *new;

	new = malloc(sizeof(struct Symbol));
	memset(new, '\0', sizeof(struct Symbol));

	new->Address = Addr;
	new->LineNumber = LineNum;
	strcpy(new->Name, Name);
	new->Next = table;
	table = new;
}
