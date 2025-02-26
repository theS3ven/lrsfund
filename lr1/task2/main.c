#include <stdio.h>
#include "limitCalculation.c"
#include "rowCalculation.c"
#include "equation.c"
#include "parser.c"

// По сути у нас должно быть 15 исчеслений, 5 строк, 3 столбца
// TODO: добавить парсер и разделить ----- и все готово
int main(int argc, char** args){
    double eps;
	int code_num = ParseArgs(argc, args, &eps);
	if (code_num != s_SUCCESS) {
		LogErrors(code_num);
		return code_num;
	}
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
    
    code_num = rowE(eps, &resultL);
    printf("Row of e = %Lf\n", resultL);
    
    code_num = rowPi(eps, &resultL);
    printf("Row of pi = %Lf\n", resultL);

    code_num = rowLn2(eps, &resultL);
    printf("Row of ln2 = %Lf\n", resultL);

    code_num = rowSqrt2(eps, &resultL);
    printf("Row of sqrt2 = %Lf\n", resultL);

    code_num = rowGamma(eps, &resultL);
    printf("Row of gamma = %Lf\n", resultL);

    printf("Equation of e = %Lf\n", bin_search(0.000001, 10.0, eps, eqE));
    printf("Equation of pi = %Lf\n", bin_search(0.000001, 2 * M_PI, eps, eqPi));
    printf("Equation of ln2 = %Lf\n", bin_search(0.000001, 10.0, eps, eqLn2));
    printf("Equation of sqrt2 = %Lf\n", bin_search(0.000001, 10.0, eps, eqSqrt2));
    printf("Equation of gamma = %Lf\n", bin_search(0.000001, 10.0, eps, eqGamma));


    return 0;
}