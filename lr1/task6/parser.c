#include "parser.h"

double parseDouble(char* input, s_STATE* code) {
	double result = 0;
	double neg = 1;
	int index = 0, len = strlen(input);
	*code = s_SUCCESS;
	if (input[index] == '-') {
		neg = -1;
		index++;
	}
	while (index < len) {
		if ('0' > input[index] || input[index] > '9') {
			break;
		}
		result *= 10;
		result += input[index] - '0';
		index++;
	}

	if (index == len) {
		return result * neg;
	}

	if (input[index] != '.') {
		*code = s_ERROR_DATA;
		return 0;
	}

	index++;
	double mult = 0.1;
	while (index < len) {
		if ('0' > input[index] || input[index] > '9') {
			*code = s_ERROR_DATA;
			return 0;
		}
		result += (input[index] - '0') * mult;
		mult *= 0.1;
		index++;
	}
	return result * neg;
}


s_STATE ParseArgs(int argc, char** args, double* precision, double* x) {
	if (argc < 2) {
		return s_NOT_ENOUGH_ARGS;
	}
	if (argc > 2) {
		return s_TOO_MANY_ARGS;
	}
	s_STATE code = s_SUCCESS;
	*precision = parseDouble(args[1], &code);
	if(code != s_SUCCESS){
		return code;
	}

	return s_SUCCESS;
}

void LogErrors(s_STATE code) {
	switch (code) {
		case s_TOO_MANY_ARGS: {
			printf("to many args provided\n");
			break;
		}
		case s_NOT_ENOUGH_ARGS: {
			printf("not enough args provided\n");
			break;
		}
		case s_INVALID_INPUT: {
			printf("invalid input, please, enter float\n");
			break;
		}
		case s_ERROR_DATA: {
			printf("type overflow, try to decrease epsilon for this calculation\n");
			break;
		}
		default: {
			printf("unknown error code\n");
			break;
		}
	}
}