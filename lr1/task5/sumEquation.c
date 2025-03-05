#include "sumEquation.h"

// Пересчитать сходимости

s_STATE firstSum(double precision, double x, long double* result){
    int n = 1;
    long double prev = 0.1L, sum = 1.0L, calc = 1.0L; 
    while(fabsl(sum - prev) > precision && n < 100000){
        prev = sum;
        calc *= (x / n);
        sum += calc;
        if(!isfinite(sum)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = sum;
    return s_SUCCESS;

}

s_STATE secSum(double precision, double x, long double* result){
    int n = 1;
    long double prev = 0.1L, sum = 1.0L, calc = 1.0L; 
    while(fabsl(sum - prev) > precision && n < 100000){
        prev = sum;
        calc *= (x * x) / (4.0 * n * n - 2.0 * n) * (-1);
        sum += calc;
        n++;
    }
    *result = sum;
    return s_SUCCESS;
}

s_STATE thirdSum(double precision, double x, long double* result){
    int n = 1;
    long double prev = 0.1L, sum = 1.0L, calc = 1.0L;
    while(fabsl(sum - prev) > precision && n < 100000){
        prev = sum;
        calc *= 9.0 * n * n * x * x / (9.0 * n * n - 9.0 * n + 2.0);
        sum += calc;
        if(x * x >= 1.0L){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = sum;
    return s_SUCCESS;
}

s_STATE fourthSum(double precision, double x, long double* result){
    int n = 2;
    long double prev = 0.1L, sum = x * x * (-0.5), calc = -0.125L; 
    while(fabsl(sum - prev) > precision && n < 100000){
        prev = sum;
        calc *= (-1.0) * (x * x) * (2.0 * n - 1) / (2.0 * n);
        sum += calc;
        if(fabsl(x) >= 1.0L){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = sum;
    return s_SUCCESS;
}