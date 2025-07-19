#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pratt.h"
#include "mem_arena.h"
#include "log.h"

void pratt_parser(char *equation, size_t n)
{
    printf("Pratt parser start\n");
    printf("%s\n", equation);
    printf("Pratt parser end\n");
}
