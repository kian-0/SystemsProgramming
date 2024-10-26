#include "headers.h"

const char* Instruction(char opcode[64])
{
    if (strcmp(opcode, "ADD") == 0)
    {
        return "18";
    } // ADD 18
    else if (strcmp(opcode, "AND") == 0)
    {
        return "40";
    } // AND 40
    else if (strcmp(opcode, "COMP") == 0)
    {
        return "28";
    } // COMP 28

    else if (strcmp(opcode, "DIV") == 0)
    {
        return "24";
    } // DIV 24
    else if (strcmp(opcode, "J") == 0)
    {
        return "3c";
    } // J 3c
    else if (strcmp(opcode, "JEQ") == 0)
    {
        return "30";
    } // JEQ 30
    else if (strcmp(opcode, "JGT") == 0)
    {
        return "30";
    } // JGT 34
    else if (strcmp(opcode, "") == 0)
    {
        return "38";
    } // JLT 38
    else if (strcmp(opcode, "") == 0)
    {
        return "48";
    } // JSUB 48
    else if (strcmp(opcode, "") == 0)
    {
        return "00";
    } // LDA 00
    else if (strcmp(opcode, "") == 0)
    {
        return "50";
    } // LDCH 50
    else if (strcmp(opcode, "") == 0)
    {
        return "08";
    } // LDL 08
    else if (strcmp(opcode, "") == 0)
    {
        return "04";
    } // LDX 04
    else if (strcmp(opcode, "") == 0)
    {
        return "20";
    } // MUL 20
    else if (strcmp(opcode, "") == 0)
    {
        return "D8";
    } // RD D8
    else if (strcmp(opcode, "") == 0)
    {
        return "4c";
    } // RSUB 4c
    else if (strcmp(opcode, "") == 0)
    {
        return "0c";
    } // STA OC
    else if (strcmp(opcode, "") == 0)
    {
        return "54";
    } // STCH 54
    else if (strcmp(opcode, "") == 0)
    {
        return "14";
    } // STL 14
    else if (strcmp(opcode, "") == 0)
    {
        return "e8";
    } // STSW E8
    else if (strcmp(opcode, "") == 0)
    {
        return "10";
    } // STX 10
    else if (strcmp(opcode, "") == 0)
    {
        return "1c";
    } // SUB 1c
    else if (strcmp(opcode, "") == 0)
    {
        return "e0";
    } // TD? E0
    else if (strcmp(opcode, "") == 0)
    {
        return "2c";
    } // TIX 2c
    else if (strcmp(opcode, "") == 0)
    {
        return "dc";
    } // WD? Dc
    else
    {
        return "00";
    }
}