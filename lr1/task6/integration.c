#include "integration.h"


double firstInteg(double x){
    return log(1.0L + x) / x;
}

double secondInteg(double x){
    return exp(-(x * x) / 2);
}

double thirdInteg(double x){
    if (x >= 1) {
		return 0.0L;
	}
	return -log(1 - x);
}

double fourthInteg(double x){
    return pow(x, x);
}

s_STATE trapezoidInteg(double (*f)(double), double* result){
    int steps = 1000;
    double step = 1.0L / steps;
    double answer = 0.0L;
    for(int i = 2; i <= steps; i++){
        double current = (f((i - 1) * step) + f(i * step)) / 2.0L * step;
        answer += current;
    }
    *result = answer;
    return s_SUCCESS;
}