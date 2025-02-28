#include "limitCalculation.h"

long double factorial(unsigned int number){
    long double f = 1;
    for(int32_t i = 1; i <= number; i++){
        f *= i;
    }

    return f;
}

// long double factorialLog(int n) {
// 	long double answ = 0.0;
// 	for (int i = 1; i <= n; i++) {
// 		answ += logl(i);
// 	}
// 	return answ;
// }

long double C(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

s_STATE limE(double precision, long double* result){
    int n = 1;
    long double prev = 0, e = 1; // начальное выражение для рекурентного подсчета
    while(fabsl(e - prev) > precision){
        prev = e;
        e = powl((1.0L + 1.0 / n), n);
        if(!isfinite(e)){  // отладка, если вышли за пределы значений с плавающей точкой
            return s_ERROR_DATA;
        }
        n++;
    }
    *result = e;
    return s_SUCCESS;
}

s_STATE limPi(double precision, long double* result){
    int n = 1;
    long double prev = 0, pi = 4;
    while(fabsl(pi - prev) > precision){
        prev = pi;
        long double calculation = (16.0L * powl(n + 1.0L, 3) * n) / (powl(2.0L * n + 2.0L, 2.0) * powl(2.0L * n + 1.0L, 2));
        pi *= calculation;
        if(!isfinite(pi)){
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
        if(!isfinite(ln2)){
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
        if(!isfinite(sqrt2)){
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

    do {
        long double sum = 0.0L;
        for(int k = 1; k <= m; k++){
            sum += C(m, k) * (powl(-1.0L, k) / k) * logl(factorial(k));
            if(!isfinite(sum)){
                return s_ERROR_DATA;
            }
        }

        prev = gamma;
        gamma = sum;
        if (!isfinite(gamma)) {
			return s_ERROR_DATA;
		}
        m++;
    } while(fabsl(gamma - prev) > precision && m < 50);
    if(fabsl(gamma) > 1.0){
        return s_ERROR_DATA;
    }
    *result = gamma;
    return s_SUCCESS;
}
