#ifndef __PARSER_ERRORS__
#define __PARSER_ERRORS__

#include "utils.h"

#define FOREACH_PARSER_ERR_STATUS(ITEM)\
    ITEM(PARSE_SUCCESS)                     \
    ITEM(PARSE_INVALID_TOKEN)               \
    ITEM(PARSE_NAN)                         \
    ITEM(PARSE_UNEXPECTED_VALUE)            \
    ITEM(PARSE_MISSING_PARENTHESIS)         \
    ITEM(PARSE_TOKEN_INDEX_OUT_OF_BOUNDS)   \
    ITEM(PARSE_OPERATOR_NOT_SUPPORTED)      \
    ITEM(PARSE_VALUE_FROM_NON_VALUE_TYPE)   \
    ITEM(PARSE_ERROR_UNKNOWN)

typedef enum {
    FOREACH_PARSER_ERR_STATUS(GENERATE_ENUM)
}parser_err_t;

const char* parser_get_err_status_str(parser_err_t err);

#endif // __PARSER_ERRORS__
