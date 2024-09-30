#include "headers.h"

void InsertSymbol(SymbolList table, char Name[7], int Addrm, int LineNum){

Symbol new;

new = malloc(sizeof(Symbol));
	memset(new, '\0', sizeof(Symbol);

new -> Address = Addr;
new -> LineNumber = LineNum;
strcpy(new -> Name, Name);
new -> Next = table;
table = &new

}
