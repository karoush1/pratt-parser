#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pratt.h"
#include "mem_arena.h"
#include "log.h"

#define MAX_TOKEN_QTY 100

#define is_operation(c) \
    (!!memchr(OP_TOKENS, (c), sizeof(OP_TOKENS)))

static char OP_TOKENS[] = "+_*/";

static int get_number_len(char *expr, int max_chars)
{
    int i = 0;
    while (expr[i] != '\0' && isdigit(expr[i]) && i < max_chars) {
        i++;
    }
    return i;
}

static const char *token_types[] = {
    FOREACH_TOKEN_TYPE(GENERATE_STRING)
};

const char* token_get_type_str(token_type_t type)
{
    return token_types[type];
}

static void token_get_expr(token_t token, char *dst)
{
    for (int i = 0; i < token.len; i++) {
        dst[i] = token.expr[i];
    }
}

void token_print_pretty(token_t token)
{
    char expr[10] = { '\0' };
    token_get_expr(token, expr);
    LOG_INFO(
        "{\n"
        "    .expr = %s\n"
        "    .len = %d\n"
        "    .type = %s\n"
        "}\n",
        expr, token.len, token_get_type_str(token.type)
    );
}

static parser_err_t tokenise_expression(char *expr, int expr_len, tokens_t *tokens)
{
    int tok_idx = 0;
    for (int i = 0; i < expr_len; i++) {
        if (tok_idx >= tokens->n_tokens) {
            return PARSE_TOKEN_INDEX_OUT_OF_BOUNDS;
        }

        // Check if character is an operation token
        if (is_operation(expr[i])) {
            LOG_INFO("Found operator '%c'\n", expr[i])
            tokens->token[tok_idx++] = (token_t){
                .expr = &expr[i],
                .len = 1,
                .type = TOKEN_OPERATOR
            };
        // Check if number token
        } else if (isdigit(expr[i])) {
            LOG_INFO("Found number '%c'...\n", expr[i]);
            int tok_len = get_number_len(&expr[i], expr_len - i);
            tokens->token[tok_idx++] = (token_t){
                .expr = &expr[i],
                .len = tok_len,
                .type = TOKEN_VALUE
            };

            char s[10] = { '\0' };
            token_get_expr(tokens->token[i], s);
            LOG_INFO("Final number is %s\n", s);

            i += tok_len;
        // Ignore character
        } else {
            LOG_INFO("Skip character. expr[%d] = %d(%c)\n", i, (int)expr[i], expr[i]);
        }
    }

    for (int i = 0; i < tokens->n_tokens && tokens->token[i].type != TOKEN_UNASSIGNED; i++) {
        printf("token[%d] = ", i);
        token_print_pretty(tokens->token[i]);
    }

    return PARSE_SUCCESS;
}

static token_t token_init_default(void)
{
    token_t token = {
        .expr = NULL,
        .len = 0,
        .type = TOKEN_UNASSIGNED
    };

    return token;
}

token_t* token_init_array(arena_t *arena, int n_tokens){
    token_t *token = arena_malloc(arena, sizeof(token_t) * n_tokens);
    for (int i = 0; i < n_tokens; i++) {
        token[i] = token_init_default();
    }

    return token;
}

static tokens_t* tokens_init(arena_t *arena, int n_tokens)
{
    tokens_t *tokens = arena_malloc(arena, sizeof(tokens_t));
    tokens->n_tokens = n_tokens;
    tokens->token = token_init_array(arena, n_tokens);

    return tokens;
}

void pratt_parser(char *equation, size_t n)
{
    printf("Pratt parser start\n");
    printf("%s\n", equation);
    arena_t *arena = arena_init(DEFAULT_ARENA_SIZE);
    tokens_t *tokens = tokens_init(arena, MAX_TOKEN_QTY);
    tokenise_expression(equation, n, tokens);
    printf("Pratt parser end\n");
}
