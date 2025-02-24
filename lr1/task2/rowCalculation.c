#include "rowCalculation.h"
#include "limitCalculation.h"

s_STATE rowE(double precision, long double* result){
    int n = 0;
    long double prev = 0.1, e = 0; // магическое число нужно для выполнения первого условия
    while(n < 1000 && (e - prev)){
        prev = e;
        e += 1.0L / factorial(n);
        if(fabsl(e) > DBL_MAX){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = e;
    return s_SUCCESS;
}