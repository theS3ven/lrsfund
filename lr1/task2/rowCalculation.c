#include "rowCalculation.h"
#include "limitCalculation.h"

s_STATE rowE(double precision, long double* result){
    int n = 0;
    long double prev = 0.1, e = 0; // магическое число нужно для выполнения первого условия
    while(n < 1000 && fabsl(e - prev) > precision){
        prev = e;
        e += 1.0L / factorial(n);
        if(!isfinite(e)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = e;
    return s_SUCCESS;
}

s_STATE rowPi(double precision, long double* result){
    int n = 1;
    double prev = 0.1, pi = 0.0L;
    while(n < 1000 && fabsl(pi - prev) > precision){
        prev = pi;
        pi += 4 * powl(-1, (n - 1)) / (2.0L * n - 1);
        if(!isfinite(pi)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = pi;
    return s_SUCCESS;
}

s_STATE rowLn2(double precision, long double* result){
    int n = 1;
    double prev = 0.1, ln2 = 0.0L;
    while(n < 1000 && fabsl(ln2 - prev) > precision){
        prev = ln2;
        ln2 += powl(-1, (n - 1)) / n;
        if(!isfinite(ln2)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = ln2;
    return s_SUCCESS;
}

s_STATE rowSqrt2(double precision, long double* result){
    int n = 2;
    double prev = 0.1, sqrt2 = 1.0L;
    while(n < 1000 && fabsl(sqrt2 - prev) > precision){
        prev = sqrt2;
        sqrt2 *= powl(2, powl(2, (-1 * n)));
        if(!isfinite(sqrt2)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = sqrt2;
    return s_SUCCESS;
}

s_STATE rowGamma(double precision, long double* result){
    int n = 2;
    double prev = 0.1, gamma = 0.0L, calculation;
    int zero_counter = 0;
    while(n < 100000000 && zero_counter < 1000){  // magic numbers again)
        prev = gamma;
        gamma += 1.0L / powl(floorl(sqrtl(n)), 2) - (1.0L / n);
        if (fabsl(gamma - prev) > precision) {
            zero_counter++;
        } else {
            zero_counter = 0;
        }
        if(!isfinite(gamma)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = -1 * M_PI * M_PI / 6 + gamma;
    return s_SUCCESS;
}