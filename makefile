project2: p2.o PrintSymbolTable.o InsertSymbol.o IsInSymbolTable.o
		gcc -o project2 p2.o PrintSymbolTable.o InsertSymbol.o IsInSymbolTable.o

p2.o: p2.c headers.h
		gcc -c -g -Wall p2.c

PrintSymbolTable.o: PrintSymbolTable.c headers.h
		gcc -c -g -Wall PrintSymbolTable.c

InsertSymbol.o: InsertSymbol.c headers.h
		gcc -c -g -Wall InsertSymbol.c

IsInSymbolTable.o: IsInSymbolTable.c headers.h
		gcc -c -g -Wall IsInSymbolTable.c

DeleteList.o: DeleteList.c headers.c
		gcc -c -g -Wall DeleteList.c