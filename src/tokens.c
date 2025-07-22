#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "tokens.h"
#include "mem_arena.h"
#include "utils.h"
#include "parser.h"
#include "log.h"

#define is_period(c) ((c) == '.')

int token_get_number_len_from_expr(char *expr, int max_chars)
{
    int i = 0, period_cnt = 0;
    while (expr[i] != '\0'
            && (isdigit(expr[i]) || is_period(expr[i]))
            && i < max_chars) {
        if (is_period(expr[i])) {
            period_cnt++;
        }

        if (period_cnt > 1) {
            return 0;
        }

        i++;
    }

    return i;
}

const char *token_types[] = {
    FOREACH_TOKEN_TYPE(GENERATE_STRING)
};

const char* token_get_type_str(token_type_t type)
{
    return token_types[type];
}

void token_get_expr(token_t token, char *dst)
{
    for (int i = 0; i < token.len; i++) {
        dst[i] = token.expr[i];
    }
}

parser_err_t token_get_value(token_t token, double *parsed_value)
{
    if (token.type != TOKEN_VALUE) {
        LOG_ERROR("Error trying to convert non-value token to value\n");
        token_print_pretty(token);

        return PARSE_VALUE_FROM_NON_VALUE_TYPE;
    }

    *parsed_value = strtod(token.expr, NULL);

    return PARSE_SUCCESS;
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

token_t token_init_default(void)
{
    token_t token = {
        .expr = NULL,
        .len = 0,
        .type = TOKEN_UNASSIGNED
    };

    return token;
}

token_t* token_init_array(arena_t *arena, int n_tokens)
{
    token_t *token = arena_malloc(arena, sizeof(token_t) * n_tokens);
    for (int i = 0; i < n_tokens; i++) {
        token[i] = token_init_default();
    }

    return token;
}

tokens_t* tokens_init(arena_t *arena, int n_tokens)
{
    tokens_t *tokens = arena_malloc(arena, sizeof(tokens_t) * n_tokens);
    tokens->n_tokens = n_tokens;
    tokens->token = token_init_array(arena, n_tokens);

    return tokens;
}
