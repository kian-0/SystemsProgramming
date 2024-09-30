project1: p1.o PrintSymbolTable.o InsertSymbol.o IsInSymbolTable.o
		gcc -o project1 p1.o PrintSymbolTable.o InsertSymbol.o IsInSymbolTable.o

p1.o: p1.c headers.h
		gcc -c -g -Wall p1.c

PrintSymbolTable.o: PrintSymbolTable.c headers.h
		gcc -c -g -Wall PrintSymbolTable.c

InsertSymbol.o: InsertSymbol.c headers.h
		gcc -c -g -Wall InsertSymbol.c

IsInSymbolTable.o: IsInSymbolTable.c headers.h
		gcc -c -g -Wall IsInSymbolTable.c
