#include <stdio.h>
#include "parser.c"
#include "integration.c"


int main(int argc, char** args){
    double eps, x;
	int code_num = ParseArgs(argc, args, &eps, &x);
	if (code_num != s_SUCCESS) {
		LogErrors(code_num);
		return code_num;
	}
    double resultL;


    code_num = trapezoidInteg(firstInteg, &resultL);
    printf("First integration = %f\n", resultL);

    code_num = trapezoidInteg(secondInteg, &resultL);
    printf("Second integration = %f\n", resultL);

    code_num = trapezoidInteg(thirdInteg, &resultL);
    printf("Third integration = %f\n", resultL);

    code_num = trapezoidInteg(fourthInteg, &resultL);
    printf("Fourth integration = %f\n", resultL);

    return 0;
}