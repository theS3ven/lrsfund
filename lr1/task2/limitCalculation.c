#include "limitCalculation.h"

unsigned long long int factorial(unsigned int number){
    int f = 1;

    for(int i = 1; i <= number; i++){
        f *= i;
    }

    return f;
}

unsigned long long int C(int n, int k){
    unsigned long long int answ = 1;
    for(int i = 0; i < k; i++){
        answ *= (n - i);
        answ /= (i + 1);
    }
    return answ;
}

// убрать рекурентность и сделать по обычному
s_STATE limE(double precision, long double* result){
    int n = 1;
    long double prev = 0, e = 1; // начальное выражение для рекурентного подсчета
    while(fabsl(e - prev) > precision){
        prev = e;
        e = powl((1 + 1.0L / n), n);
        if(fabsl(e) > DBL_MAX){  // отладка, если вышли за пределы значений с плавающей точкой
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = e;
    return s_SUCCESS;
}

s_STATE limPi(double precision, long double* result){
    int n = 1;
    long double prev = 0, pi = powl(powl(2, n) * factorial(n), 4) / powl((n * (factorial(2 * n))), 2);
    while(fabsl(pi - prev) > precision){
        prev = pi;
        long double calculation = (4 * powl(n, 2) + 4 * n) / powl((2 * n + 1), 2);
        pi *= calculation;
        if(fabsl(pi) > DBL_MAX){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = pi;
    return s_SUCCESS;
}

s_STATE limLn2(double precision, long double* result){
    int n = 1;
    long double prev = 0, ln2 = n * (powl(2, (1.0L / n)) - 1);
    while(fabsl(ln2 - prev) > precision){
        prev = ln2;
        long double calculation = (n * powl(2, (1.0L / (n + 1))) - n + powl(2, (1.0L / (n + 1))) - 1) / (n * powl(2, (1.0L / n)) - n);
        ln2 *= calculation;
        if(fabsl(ln2) > DBL_MAX){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = ln2;
    return s_SUCCESS;
}

s_STATE limSqrt2(double precision, long double* result){
    int n = 1;
    long double prev = 0, sqrt2 = -0.5;
    while(fabsl(sqrt2 - prev) > precision){
        prev = sqrt2;
        long double calculation = prev - powl(prev, 2) / 2 + 1;
        sqrt2 = calculation;
        if(fabsl(sqrt2) > DBL_MAX){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = sqrt2;
    return s_SUCCESS;
}

s_STATE limGamma(double precision, long double* result){
    long double prev = 0.0, gamma = 1.0;
    int m = 1;
    while(fabsl(gamma - prev) > precision && m < 100){
        long double sum = 0.0L;
        for(int k = 1; k <= m; k++){
            sum += C(m, k) * (powl(-1.0L, k) / k) * log(factorial(k));
            if(fabsl(sum) > DBL_MAX){
                return s_ERROR_DATA;
            }
        }
        if(sum > 1.0){
            break;
        }
        prev = gamma;
        gamma = sum;
        if((fabsl(gamma)) > DBL_MAX){
            return s_ERROR_DATA;
        }
        m++;
    }
    if(fabsl(gamma) > 1.0){
        return s_ERROR_DATA;
    }
    *result = gamma;
    return s_SUCCESS;
}
