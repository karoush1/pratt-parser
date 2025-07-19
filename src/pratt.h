#ifndef __PRATT_PARSER__
#define __PRATT_PARSER__

#include <stdlib.h>

typedef enum {
    PARSE_SUCCESS,
    PARSE_INVALID_TOKEN,
    PARSE_VALUE_ERROR,
    PARSE_MISSING_PARENTHESIS,
    PARSE_TOKEN_INDEX_OUT_OF_BOUNDS,
}parser_err_t;

void pratt_parser(char *equation, size_t n);

#endif // __PRATT_PARSER__
