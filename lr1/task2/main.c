#include <stdio.h>
#include "limitCalculation.c"


// По сути у нас должно быть 15 исчеслений, 5 строк, 3 столбца
int main(){
    double eps = 0.0001;
    int code_num = 0;
    long double resultL;

    code_num = limE(eps, &resultL);
    printf("Limit of e = %Lf\n", resultL);

    code_num = limPi(eps, &resultL);
    printf("Limit of Pi = %Lf\n", resultL);

    code_num = limLn2(eps, &resultL);
    printf("Limit of ln2 = %Lf\n", resultL);

    code_num = limSqrt2(eps, &resultL);
    printf("Limit of sqrt2 = %Lf\n", resultL);

    code_num = limGamma(eps, &resultL);
    printf("Limit of gamma = %Lf\n", resultL);
    return 0;
}