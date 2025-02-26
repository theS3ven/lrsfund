#ifndef EQUATIONCALCULATION_H
#define EQUATIONCALCULATION_H

#include "states.h"

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>

long double bin_search(double, double, double, long double (*)(long double));
void eratosthen(bool*, int);
long double calculateGamma(double);
long double eqE(long double);
long double eqPi(long double);
long double eqLn2(long double);
long double eqSqrt2(long double);
long double eqGamma(long double);

#endif