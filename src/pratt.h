#ifndef __PRATT_PARSER__
#define __PRATT_PARSER__

#include <stdlib.h>

#include "utils.h"

#define FOREACH_PARSER_ERR_STATUS(ITEM)\
    ITEM(PARSE_SUCCESS)                     \
    ITEM(PARSE_INVALID_TOKEN)               \
    ITEM(PARSE_VALUE_ERROR)                 \
    ITEM(PARSE_MISSING_PARENTHESIS)         \
    ITEM(PARSE_TOKEN_INDEX_OUT_OF_BOUNDS)   \
    ITEM(PARSE_OPERATOR_NOT_SUPPORTED)      \
    ITEM(PARSE_ERROR_UNKNOWN)

typedef enum {
    FOREACH_PARSER_ERR_STATUS(GENERATE_ENUM)
}parser_err_t;

parser_err_t pratt_parser(char *equation, size_t n);
const char* pratt_get_err_status_str(parser_err_t err);

#endif // __PRATT_PARSER__
