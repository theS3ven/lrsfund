#include "bin_search.h"
#include "states.h"

long double bin_search(double left, double right, double fault, long double (*func)(long double x)){
    long double mid;

    if(fault <= 0L){
        return s_ERROR_EPSILON;
    }
    if(func(left) * func(right) > 0L){
        return s_NO_ROOTS;
    }

    while (fabsl(right - left) > fault){
        mid = (left + right) / 2.0;
        long double f_left = func(left);
        long double f_right = func(right);
        long double f_mid = func(mid);
        if (fabs(f_mid) < fault){
            return mid;
        }if (f_mid * f_left < 0){
            right = mid;
        }if (f_mid * f_right < 0){
            left = mid;
        }
    }
    return (left + right) / 2.0;
    
}

long double eqE(long double x) {
    return log(x) - 1.0;
}

long double eqX(long double x){
    return x - 10.0;
}

long double eqLn2(long double x){
    return powl(expl(1), x) - 2.0;
}

long double eqSqrt2(long double x){
    return x * x - 2.0;
}

