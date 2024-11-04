#include "headers.h"

int IsDirective(char symbol[7])
{
    if (strcmp(symbol, "START") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "END") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "BYTE") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "WORD") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "RESB") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "RESW") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "RESR") == 0)
    {
        return 0;
    }
    else if (strcmp(symbol, "EXPORTS") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}