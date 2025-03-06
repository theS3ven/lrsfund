#include <stdio.h>
#include "bin_search.c"
#include "parser.c"
#include "states.h"

// NULL

int main(int argc, char** args){
    double eps;
	int code_num = ParseArgs(argc, args, &eps);
	if (code_num != s_SUCCESS) {
		LogErrors(code_num);
		return code_num;
	}
    double result;
    if(bin_search(&result, 9, 12.0, eps, NULL) == s_SUCCESS){
        printf("%f", result);
    }else{
        printf("Error %u\n", bin_search(&result, 11, 12.0, eps, eqX));
    }

    return 0;
}