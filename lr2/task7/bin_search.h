#ifndef BIN_SEARCH_H
#define BIN_SEARCH_H

#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>
#include <stdbool.h>


long double bin_search(double, double, double, long double (*)(long double));
long double eqE(long double);
long double eqX(long double);
long double eqLn2(long double);
long double eqSqrt2(long double);

#endif