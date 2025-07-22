#ifndef __TOKENS__
#define __TOKENS__

#include <string.h>

#include "parser.h"
#include "mem_arena.h"
#include "utils.h"

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

#define MAX_TOKEN_QTY 50

#define OP_TOKENS "+-*/"

#define is_operation(c) \
    (!!memchr(OP_TOKENS, (c), sizeof(OP_TOKENS)))

const char* token_get_type_str(token_type_t type);
int token_get_number_len(char *expr, int max_chars);
void token_get_expr(token_t token, char *dst);
void token_print_pretty(token_t token);
token_t token_init_default(void);
token_t* token_init_array(arena_t *arena, int n_tokens);
tokens_t* tokens_init(arena_t *arena, int n_tokens);

#endif // __TOKENS__
