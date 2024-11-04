#include "headers.h"

// Translates string opcode and returns hex interpretation
const char *Instruction(char opcode[64])
{
    // OPCODE HEX (F)ormat #s
    if (strcmp(opcode, "ADD") == 0)
    {
        return "18";
    } // ADD 18 F 3/4
    else if (strcmp(opcode, "ADDF") == 0)
    {
        return "58";
    } // ADDF 58 F 3/4
    else if (strcmp(opcode, "ADDR") == 0)
    {
        return "90";
    } // ADDR 90 F 2
    else if (strcmp(opcode, "AND") == 0)
    {
        return "40";
    } // AND 40 F 3/4
    else if (strcmp(opcode, "CLEAR") == 0)
    {
        return "B4";
    } // CLEAR F 2
    else if (strcmp(opcode, "COMP") == 0)
    {
        return "28";
    } // COMP 28 F 3/4
    else if (strcmp(opcode, "COMPF") == 0)
    {
        return "88";
    } // COMPF 88 F 3/4
    else if (strcmp(opcode, "COMR") == 0)
    {
        return "a0";
    } // COMPR a0 F 2
    else if (strcmp(opcode, "DIV") == 0)
    {
        return "24";
    } // DIV 24 F 3/4
    else if (strcmp(opcode, "DIVF") == 0)
    {
        return "24";
    } // DIVR 64 F 3/4
    else if (strcmp(opcode, "DIVR") == 0)
    {
        return "9c";
    } // DIV 9c F 2
    else if (strcmp(opcode, "FIX") == 0)
    {
        return "24";
    } // FIX c4 F 1
    else if (strcmp(opcode, "FLOAT") == 0)
    {
        return "24";
    } // FLOAT c0 F 1
    else if (strcmp(opcode, "HIO") == 0)
    {
        return "f4";
    } // HIO f4 F 1

    else if (strcmp(opcode, "J") == 0)
    {
        return "3c";
    } // J 3c F 3/4
    else if (strcmp(opcode, "JEQ") == 0)
    {
        return "30";
    } // JEQ 30 F 3/4
    else if (strcmp(opcode, "JGT") == 0)
    {
        return "30";
    } // JGT 34 F 3/4
    else if (strcmp(opcode, "JLT") == 0)
    {
        return "38";
    } // JLT 38 F 3/4
    else if (strcmp(opcode, "JSUB") == 0)
    {
        return "48";
    } // JSUB 48 F 3/4
    else if (strcmp(opcode, "LDA") == 0)
    {
        return "00";
    } // LDA 00 F 3/4
    else if (strcmp(opcode, "LDB") == 0)
    {
        return "68";
    } // LDB 68 F 3/4
    else if (strcmp(opcode, "LDCH") == 0)
    {
        return "50";
    } // LDCH 50 F 3/4
    else if (strcmp(opcode, "LDF") == 0)
    {
        return "70";
    } // LDF 70 F 3/4
    else if (strcmp(opcode, "LDL") == 0)
    {
        return "08";
    } // LDL 08 F 3/4
    else if (strcmp(opcode, "LDS") == 0)
    {
        return "6c";
    } // LDA 6c F 3/4
    else if (strcmp(opcode, "LDT") == 0)
    {
        return "74";
    } // LDA 74 F 3/4
    else if (strcmp(opcode, "LDX") == 0)
    {
        return "04";
    } // LDX 04 F 3/4
    else if (strcmp(opcode, "MUL") == 0)
    {
        return "20";
    } // MUL 20 F 3/4
    else if (strcmp(opcode, "MULF") == 0)
    {
        return "60";
    } // MULF 60 F 3/4
    else if (strcmp(opcode, "MULR") == 0)
    {
        return "98";
    } // MULR 98 F 2
    else if (strcmp(opcode, "NORM") == 0)
    {
        return "c8";
    } // NORM c8 F 1
    else if (strcmp(opcode, "OR") == 0)
    {
        return "44";
    } // OR 44 F 3/4
    else if (strcmp(opcode, "RD") == 0)
    {
        return "d8";
    } // RD d8 F 3/4
    else if (strcmp(opcode, "RMO") == 0)
    {
        return "d8";
    } // MUL d8 F 2
    else if (strcmp(opcode, "RSUB") == 0)
    {
        return "4c";
    } // RSUB 4c F 3/4
    else if (strcmp(opcode, "SHIFTL") == 0)
    {
        return "a4";
    } // SHIFTL a4 F 2
    else if (strcmp(opcode, "SHIFTR") == 0)
    {
        return "a8";
    } // SHIFTL a8 F 2
    else if (strcmp(opcode, "SIO") == 0)
    {
        return "f0";
    } // SIO f0 F1
    else if (strcmp(opcode, "SKK") == 0)
    {
        return "e0";
    } // SKK e0 F 3/4
    else if (strcmp(opcode, "STA") == 0)
    {
        return "0c";
    } // STA OC F 3/4
    else if (strcmp(opcode, "STB") == 0)
    {
        return "78";
    } // STB 78 F 3/4
    else if (strcmp(opcode, "STCH") == 0)
    {
        return "54";
    } // STCH 54 F 3/4
    else if (strcmp(opcode, "STF") == 0)
    {
        return "80";
    } // STF 80 F 3/4
    else if (strcmp(opcode, "STL") == 0)
    {
        return "14";
    } // STL 14 F 3/4
    else if (strcmp(opcode, "STI") == 0)
    {
        return "D4";
    } // STI D4 F 3/4
    else if (strcmp(opcode, "STSW") == 0)
    {
        return "e8";
    } // STSW E8 F 3/4
    else if (strcmp(opcode, "STT") == 0)
    {
        return "84";
    } // STT 84 F 3/4
    else if (strcmp(opcode, "STX") == 0)
    {
        return "10";
    } // STX 10 F 3/4
    else if (strcmp(opcode, "SUB") == 0)
    {
        return "1c";
    } // SUB 1c F 3/4
    else if (strcmp(opcode, "SUBF") == 0)
    {
        return "5c";
    } // SUBF 5c F 3/4
    else if (strcmp(opcode, "SUBR") == 0)
    {
        return "94";
    } // SUBR 94 F 3/4
    else if (strcmp(opcode, "TD") == 0)
    {
        return "e0";
    } // TD? E0 F 3/4
    else if (strcmp(opcode, "TIO") == 0)
    {
        return "f8";
    } // SUB f8 F 1
    else if (strcmp(opcode, "TIX") == 0)
    {
        return "2c";
    } // TIX 2c F 3/4
    else if (strcmp(opcode, "TIXR") == 0)
    {
        return "b8";
    } // TIX 2c F 2
    else if (strcmp(opcode, "WD") == 0)
    {
        return "dc";
    } // WD? dc F 3/4
    else
    {
        return "!!!!missread!!!!";
    }
}