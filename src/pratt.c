#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pratt.h"
#include "tokens.h"
#include "mem_arena.h"
#include "utils.h"
#include "log.h"

const char *pratt_err_status_str[] = {
    FOREACH_TOKEN_TYPE(GENERATE_STRING)
};

const char* pratt_get_err_status_str(parser_err_t err)
{
    return pratt_err_status_str[err];
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
            int tok_len = token_get_number_len(&expr[i], expr_len - i);
            tokens->token[tok_idx++] = (token_t){
                .expr = &expr[i],
                .len = tok_len,
                .type = TOKEN_VALUE
            };

            char s[10] = { '\0' };
            token_get_expr(tokens->token[i], s);
            LOG_INFO("Final number is %s\n", s);

            i += tok_len;
        // Ignore character or invalid token
        } else {
            if (isspace(expr[i])) {
                LOG_INFO("Skip character. expr[%d] = %d(%c)\n", i, (int)expr[i], expr[i]);
            } else if (isalpha(expr[i])) {
                LOG_INFO("Received character. expr[%d] = %c\n", i, expr[i]);
                return PARSE_VALUE_ERROR;
            } else if (ispunct(expr[i])) {
                return PARSE_OPERATOR_NOT_SUPPORTED;
            } else {
                LOG_ERROR("Should never reach here. Why? expr[%d] = %d(%c)\n", i, (int)expr[i], expr[i]);
                return PARSE_ERROR_UNKNOWN;
            }
        }
    }

    for (int i = 0; i < tokens->n_tokens && tokens->token[i].type != TOKEN_UNASSIGNED; i++) {
        printf("token[%d] = ", i);
        token_print_pretty(tokens->token[i]);
    }

    return PARSE_SUCCESS;
}

parser_err_t pratt_parser(char *equation, size_t n)
{
    printf("Pratt parser start\n");
    printf("%s\n", equation);

    arena_t *arena = arena_init(DEFAULT_ARENA_SIZE);
    tokens_t *tokens = tokens_init(arena, MAX_TOKEN_QTY);

    parser_err_t err = tokenise_expression(equation, n, tokens);
    if (err) {
        LOG_ERROR("Something went wrong. Parser returned err = %s\n", pratt_get_err_status_str(err));
    }
    printf("Pratt parser end\n");
}
