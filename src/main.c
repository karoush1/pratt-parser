#include <stdio.h>
#include <stdlib.h>

#include "pratt.h"

int main(int argc, char **argv)
{
    printf("argc=%d, argv=[", argc);
    for (int i = 0; i < argc; i++) { printf("%s ", argv[i]); }
    printf("%s]\n", argv[argc]);

    pratt_parser("2 + 2");
    pratt_parser("2 - 2");
    pratt_parser("2 * 2");
    pratt_parser("2 / 2");

    pratt_parser("2+2");
    pratt_parser("2-2");
    pratt_parser("2*2");
    pratt_parser("2/2");

    return EXIT_SUCCESS;
}
