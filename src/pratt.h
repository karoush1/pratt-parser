#ifndef __PRATT_PARSER__
#define __PRATT_PARSER__

#include <stddef.h>

#include "parser.h"

parser_err_t pratt_parser(char *equation, size_t n);

#endif // __PRATT_PARSER__
