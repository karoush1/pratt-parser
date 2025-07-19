#ifndef __PRATT_PARSER__
#define __PRATT_PARSER__

#include <stdlib.h>

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

typedef enum {
    PARSE_SUCCESS,
    PARSE_INVALID_TOKEN,
    PARSE_VALUE_ERROR,
    PARSE_MISSING_PARENTHESIS,
    PARSE_TOKEN_INDEX_OUT_OF_BOUNDS,
}parser_err_t;

#define FOREACH_TOKEN_TYPE(ITEM)  \
    ITEM(TOKEN_VALUE)       \
    ITEM(TOKEN_OPERATOR)    \
    ITEM(TOKEN_UNASSIGNED)  \
    ITEM(TOKEN_ERROR)

typedef enum {
    FOREACH_TOKEN_TYPE(GENERATE_ENUM)
}token_type_t;

typedef struct {
    char *expr;
    int len;
    token_type_t type;
}token_t;

typedef struct {
    token_t *token;
    int n_tokens;
} tokens_t;

void pratt_parser(char *equation, size_t n);
const char* token_get_type_str(token_type_t type);

#endif // __PRATT_PARSER__
