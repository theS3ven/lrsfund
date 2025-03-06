#ifndef PARSER_H
#define PARSER_H

#include <string.h>

#include "states.h"

s_STATE ParseArgs(int, char**, double*);
void LogErrors(s_STATE);

#endif
