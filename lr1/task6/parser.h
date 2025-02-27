#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "states.h"

s_STATE ParseArgs(int, char**, double*, double*);
void LogErrors(s_STATE);

#endif