#include <stdio.h>
#include "parser.c"
#include "sumEquation.c"


int main(int argc, char** args){
    double eps, x;
	int code_num = ParseArgs(argc, args, &eps, &x);
	if (code_num != s_SUCCESS) {
		LogErrors(code_num);
		return code_num;
	}
    long double resultL;


    code_num = firstSum(eps, x, &resultL);
    if(!code_num){
        printf("First equation = %Lf\n", resultL);
    }else{
        printf("Row is diverges\n");
    }
    code_num = secSum(eps, x, &resultL);
    if(!code_num){
        printf("Second equation = %Lf\n", resultL);
    }else{
        printf("Row is diverges\n");
    }
    code_num = thirdSum(eps, x, &resultL);
    if(!code_num){
    printf("Third equation = %Lf\n", resultL);
    }else{
        printf("Row is diverges\n");
    }
    code_num = fourthSum(eps, x, &resultL);
    if(!code_num){
    printf("Fourth equation = %Lf\n", resultL);
    }else{
        printf("Row is diverges\n");
    }
    return 0;
}