#include <stdio.h>
#include "bin_search.c"
#include "parser.c"
#include "states.h"

int main(int argc, char** args){  //TODO if *f in borders
    double eps;
	int code_num = ParseArgs(argc, args, &eps);
	if (code_num != s_SUCCESS) {
		LogErrors(code_num);
		return code_num;
	}
    // double resultL;
    printf("%Lf\n", bin_search(0.000001, 12.0, eps, eqX));




}