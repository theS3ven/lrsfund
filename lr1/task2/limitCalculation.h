#ifndef LIMITCALCULATION_H
#define LIMITCALCULATION_H

#include "states.h"

#include <stdio.h>
#include <math.h>
#include <float.h>


s_STATE limE(double, long double*);
s_STATE limPi(double, long double*);
s_STATE limLn2(double, long double*);
s_STATE limSqrt2(double, long double*);
s_STATE limGamma(double, long double*);

#endif