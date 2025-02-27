#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <stdio.h>
#include <math.h>

#include "states.h"

s_STATE trapezoidInteg(double (*)(double), double*);

double firstInteg(double);
double secondInteg(double);

#endif