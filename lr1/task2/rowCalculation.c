#include "rowCalculation.h"
#include "limitCalculation.h"

s_STATE rowE(double precision, long double* result){
    int n = 1;
    long double prev = 0.1, e = 2; // магическое число нужно для выполнения первого условия
    long double calc = 1;
    while(fabsl(e - prev) > precision){
        prev = e;
        calc *= 1.0L / (n + 1);
        e += calc;
        if(!isfinite(e)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = e;
    return s_SUCCESS;
}

s_STATE rowPi(double precision, long double* result){
    int n = 1, sign = 1;
    double prev = 0.1, pi = 0.0L;
    long double calc = 0;
    while(fabsl(pi - prev) > precision){
        prev = pi;
        calc = sign / (2 * n - 1.0L);
        pi += calc;
        if(!isfinite(pi)){
            return s_ERROR_DATA;
        }
        sign *= -1;
        n++;
    }
    *result = 4 * pi;
    return s_SUCCESS;
}

s_STATE rowLn2(double precision, long double* result){
    int n = 1;
    double prev = 0.1, ln2 = 0.0L, sign = 1.0L;
    long double calc = 0;
    while(fabsl(ln2 - prev) > precision){
        prev = ln2;
        calc = sign / n;
        ln2 += calc;
        if(!isfinite(ln2)){
            return s_ERROR_DATA;
        }
        sign *= -1;
        n++;
    }
    *result = ln2;
    return s_SUCCESS;
}

s_STATE rowSqrt2(double precision, long double* result){
    int n = 3;
    double prev = 0.1, sqrt2, calc = powl(2.0, 0.25);
    sqrt2 = calc;
    while(fabsl(sqrt2 - prev) > precision){
        prev = sqrt2;
        calc = powl(calc, 0.5);
        sqrt2 *= calc;
        if(!isfinite(sqrt2)){
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = sqrt2;
    return s_SUCCESS;
}

s_STATE rowGamma(double precision, long double* result){
    double previous = 0;
    double current = 0.5;
    int k = 2;
    double l = 0;
    do
    {
        previous = current;
        k++;
        l = sqrt(k);
        if (fmod(l, 1.0) == 0)
        {
            k++;
            l = (int)pow(k, 1.0 / 2.0);
        }
        current += 1.0 / pow((int)l, 2.0) - 1.0 / k;

    } while (fabs(previous - current) >= precision);

    *result = (current - pow(M_PI, 2) / 6);
    return s_SUCCESS;
}