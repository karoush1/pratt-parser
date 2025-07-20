#include <stdio.h>
#include <stdlib.h>

#include "pratt.h"

int main(int argc, char **argv)
{
    printf("argc=%d, argv=[", argc);
    for (int i = 0; i < argc - 1; i++) { printf("%s ", argv[i]); }
    printf("%s]\n", argv[argc]);

    char expr1[] = "1 + 2 * 3 - 456 / 789";
    pratt_parser(expr1, sizeof(expr1));

    char expr2[] = "1+2*3-456/789";
    pratt_parser(expr2, sizeof(expr2));

    char expr3[] = "111^2";
    pratt_parser(expr3, sizeof(expr3));

    char expr4[] = "11 * (22 + 333)";
    pratt_parser(expr4, sizeof(expr4));

    char expr5[] = "a";
    pratt_parser(expr5, sizeof(expr5));

    return 0;
}
