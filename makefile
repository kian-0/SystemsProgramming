project1: p1.o PrintSymbolTable.o
		gcc -o project1 p1.o PrintSymbolTable.o

p1.o: p1.c headers.h
		gcc -c -g -Wall p1.c

PrintSymbolTable.o: PrintSymbolTable.c headers.h
		gcc -c -g -Wall PrintSymbolTable.c

IsInSymbolTable.o: IsInSymbolTable.c headers.h
		gcc -c -g -Wall IsInSymbolTable.c

InsertSymbolTable.o: InsertSymbolTable.c headers.c
		gcc -c -g -Wall InsertSymbolTable.c