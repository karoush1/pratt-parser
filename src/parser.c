#include "parser.h"
#include "utils.h"

static const char *parser_err_status_str[] = {
    FOREACH_PARSER_ERR_STATUS(GENERATE_STRING)
};

const char* parser_get_err_status_str(parser_err_t err)
{
    return parser_err_status_str[err];
}
