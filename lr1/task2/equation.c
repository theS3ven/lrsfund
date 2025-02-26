#include "equation.h"
#include "limitCalculation.h"

long double bin_search(double left, double right, double fault, long double (*func)(long double x)){
    long double mid;
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

void eratosthen(bool *primes, int n){ // TODO в header
    for(int i = 0; i <= n; i++){
        primes[i] = true;
    }
    primes[0] = primes[1] = 0;
    for(int p = 2; p * p <= n; p++){
        if(primes[p]){
            for(int i = p * p; i <= n; i += p){
                primes[i] = false;
            }
        }
    }
}

long double calculateGamma(double fault){
    int x = ceill(10.0L / fault);

    bool* primes = (bool*)malloc((x) * sizeof(bool));
    if(!primes){
        exit(1);
    }
    eratosthen(primes, x);
    long double prod = 1.0;
    for(int p = 2; p <= x; p++){
        if(primes[p]){
            prod *= (1.0L - 1.0L / (long double)p);
        }
    }
    free(primes);
    return log(x) * prod;
}
// далее нужно описать сами функции, которые подставляем в м. дитохомии

long double eqE(long double x) {
    return log(x) - 1.0;
}

long double eqPi(long double x){
    return cosl(x) + 1.0;
}

long double eqLn2(long double x){
    return powl(expl(1), x) - 2.0;
}

long double eqSqrt2(long double x){
    return x * x - 2.0;
}

long double eqGamma(long double x){
    return powl(expl(1), -x) - calculateGamma(0.000001);
}