project2: p2.o PrintSymbolTable.o InsertSymbol.o IsInSymbolTable.o Pass2.o InsertTRecord.o InsertMRecord.o Instruction.o GenerateObjectFile.o DeleteList.o
		gcc -o project2 p2.o PrintSymbolTable.o InsertSymbol.o IsInSymbolTable.o Pass2.o InsertTRecord.o InsertMRecord.o Instruction.o GenerateObjectFile.o DeleteList.o

p2.o: p2.c headers.h
		gcc -c -g -Wall p2.c

PrintSymbolTable.o: PrintSymbolTable.c headers.h
		gcc -c -g -Wall PrintSymbolTable.c

InsertSymbol.o: InsertSymbol.c headers.h
		gcc -c -g -Wall InsertSymbol.c

IsInSymbolTable.o: IsInSymbolTable.c headers.h
		gcc -c -g -Wall IsInSymbolTable.c

Pass2.o: Pass2.c headers.h
		gcc -c -g -Wall Pass2.c

InsertTRecord.o: InsertTRecord.c headers.h
		gcc -c -g -Wall InsertTRecord.c

InsertMRecord.o: InsertMRecord.c headers.h
		gcc -c -g -Wall InsertMRecord.c

Instruction.o: Instruction.c headers.h
		gcc -c -g -Wall Instruction.c

GenerateObjectFile.o: GenerateObjectFile.c headers.h
		gcc -c -g -Wall GenerateObjectFile.c

DeleteList.o: DeleteList.c headers.h
		gcc -c -g -Wall DeleteList.c