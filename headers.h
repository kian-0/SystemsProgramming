#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Symbol
{
    char Name[7];
    int Address;
    int LineNumber;
    struct Symbol *Next;
};

typedef struct Symbol SYMBOL;

typedef struct Symbol *SymbolList;

struct tRecord
{

    int Start;
    int Length;
    char Code[60];
    struct tRecord *Next;
    
};

typedef struct tRecord TRECORD;

typedef struct tRecord *tRecordList;

struct mRecord
{

    int Start;
    int Length;
    char Flag;
    char Symbol[5];
    struct mRecord *Next;
};

typedef struct mRecord MRECORD;

typedef struct mRecord *mRecordList;

struct hRecord
{

    char Name[7];
    int Start;
    int Size;
};

typedef struct hRecord HRECORD;

struct eRecord
{
    int Address;
};

typedef struct eRecord ERECORD;

SymbolList Pass1(char filename[32]);

void Pass2(SymbolList table, char filename[32]);

void PrintSymbolTable(SymbolList table);

int IsInSymbolTable(SymbolList table, char Test[7]);

void InsertSymbol(SymbolList *table, char Name[7], int Addr, int LineNum);

void DeleteList(SymbolList table);

void DeleteTList(tRecordList rtable);

void DeleteMList(mRecordList mtable);

void InsertTRecord(tRecordList *rtable, int Start, int Length, char Code[60]);

void InsertMRecord(mRecordList *mtable, int Start, int Length, char Flag, char Symbol[7]);

const char *Instruction(char opcode[64]);

void GenerateObjectFile(char filename[32], HRECORD hRecord, tRecordList rtable, mRecordList mtable, ERECORD eRecord);

int IsDirective(char symbol[7]);