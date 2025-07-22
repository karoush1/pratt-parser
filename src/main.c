#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pratt.h"

int main(int argc, char **argv)
{
    printf("argc=%d, argv=[", argc);
    for (int i = 0; i < argc - 1; i++) { printf("%s ", argv[i]); }
    printf("%s]\n", (argc == 1) ? "" : argv[argc]);

    char *test_expr;

    // Simple test with spaces
    test_expr = "1.1 + 2.2 * 3.3 - 456.456 / 789.789";
    pratt_parser(test_expr, strlen(test_expr));

    // Simple test without spaces
    test_expr = "1.1+2.2*3.3-456.456/789.789";
    pratt_parser(test_expr, strlen(test_expr));

    // Test for operator precedence with parenthesis
    test_expr = "11 * (22 + 333)";
    pratt_parser(test_expr, strlen(test_expr));

    // Test for invalid number
    test_expr = "11.1 + 22.2.3";
    pratt_parser(test_expr, strlen(test_expr));

    // Test for unsupported operation
    test_expr = "111^2";
    pratt_parser(test_expr, strlen(test_expr));

    // Test for characters
    test_expr = "a";
    pratt_parser(test_expr, strlen(test_expr));

    return 0;
}
