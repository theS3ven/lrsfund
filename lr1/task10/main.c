#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "states.h"

s_STATE numCheck(char number[99], int len, int base){
    s_STATE code = s_SUCCESS;
    for(int i = 0; i < len; i++){
        if(i == 0 && number[i] == '-'){
            continue;
        }else if (number[i] >= '0' && number[i] <= '9'){
            if(number[i] - '0' >= base){
                code = s_ERROR_BASE;
            }
        }else if(number[i] >= 'A' && number[i] <= 'Z'){
            if(number[i] - 'A' + 10 >= base){
                code = s_ERROR_BASE;
            }
        }else{
            code = s_INVALID_INPUT;
            break;
        }
    }
    return code;
}

int fromBase(char number[99], int len, int base){
    int result = 0;
    len--;
    for(int i = len; i >= 0; i--){
        if(i == 0 && number[i] == '-'){
            return -result;
        }
        int multiple = 0;
        if(number[i] >= '0' && number[i] <= '9'){
            multiple = number[i] - '0';
        }else if(number[i] >= 'A' && number[i] <= 'Z'){
            multiple = number[i] - ('A' - 10);
        }
        result += pow(base, len - i) * multiple;;
    }
    return result;
}

void writeInBase(int decimal, int base){
    int len = 0;
    char number[99];
    if(decimal < 0){
        printf("-");
        decimal *= (-1);
    }
    while(decimal){
        int digit = decimal % base;
        if(digit <= 9){
            number[len] = '0' + digit;
        }else{
            number[len] = 'A' + (digit - 10);
        }
        len++;
        decimal /= base;
    }
    for(int i = len - 1; i >= 0; i--){
        printf("%c", number[i]);
    }
    printf("\n");
}

int main(int argc, char** args){
    int base;
    scanf("%d", &base); 
    if(base < 2 || base > 36){
        printf("Base if out of bounds\n");
        return s_ERROR_BASE;
    }
    char c;
    char string[99];
    int stringLen, max = INT_MIN;
    s_STATE code = s_SUCCESS;
    while(code == s_SUCCESS){
        memset(string, 0, sizeof(string));
        stringLen = 0;
        while((c = getchar()) != ' ' && c != '\t' && c != '\n'){
            string[stringLen] = c;
            stringLen++;
        }

        if(stringLen == 0){
            continue;
        }
        if(strncmp(string, "Stop", 4) == 0 && stringLen == 4){
            break;
        }
        printf("string = %s\n", string);
        if(numCheck(string, stringLen, base) != 0){
            code = numCheck(string, stringLen, base);
            break;
        }
        int decimal = fromBase(string, stringLen, base);
        if(abs(decimal) > abs(max)){
            max = decimal;
        }
    }
    if(code != s_SUCCESS){
        printf("Something went wrong\n");
        return code;
    }
    printf("Max number = ");
    writeInBase(max, base);
    for(int i = 1; i < 5; i++){
        printf("Base = %d Number = ", 9 * i);
        writeInBase(max, 9 * i);
    }
    return 0;
}