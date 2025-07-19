#include <stdio.h>
#include <stdlib.h>

#include "pratt.h"

int main(int argc, char **argv)
{
    printf("argc=%d, argv=[", argc);
    for (int i = 0; i < argc - 1; i++) { printf("%s ", argv[i]); }
    printf("%s]\n", argv[argc]);

    pratt_parser("2 + 2", 6);
    pratt_parser("2 - 2", 6);
    pratt_parser("2 * 2", 6);
    pratt_parser("2 / 2", 6);

    pratt_parser("2+2", 4);
    pratt_parser("2-2", 4);
    pratt_parser("2*2", 4);
    pratt_parser("2/2", 4);

    return EXIT_SUCCESS;
}
