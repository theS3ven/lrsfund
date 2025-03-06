#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 64

int add(int x, int y)
{
    int keep = (x & y) << 1;
    int res = x ^ y;
    if (keep == 0)
        return res;

    return add(keep, res);
}

int negative(int x)
{
    return add(~x, 1);
}

typedef enum {
    OK,
    ERROR
} s_STATES;

s_STATES decimal_to_base2r(int num, int r, char* output, int* index) {
    int mask, digit;
    char base[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", flag = 0;
    *index = 0;
    
    if (num < 0)
    {
        num = negative(num);
        flag = '1';
    }
    do{
        mask = add(1 << r, -1);
        digit = num & mask;
        num >>= r;
        output[*index] = base[digit];
        *index = add(*index, 1);
    }while(num);

    if(flag){
        output[*index] = '-';
        *index = add(*index, 1);
    }
    return OK;
}

void result(const char* output, int r, int index){
    int i;
    printf("Ваше число в системе с основанием 2^%d: ", r);
    for (i = add(index, -1); i >= 0; i = add(i, -1)){
        putchar(output[i]);
    }
    putchar('\n');
}


int main() {
    int number, index;
    int r, negative = 0;
    char buffer[BUFFER_SIZE];

    printf("Введите число (в десятичной системе): ");
    scanf("%d", &number);
    printf("Введите значение r (1 <= r <= 5): ");
    scanf("%d", &r);
    if (r < 1 || r > 5) {
        fprintf(stderr, "Неверное значение r. Оно должно быть в диапазоне [1, 5].\n");
        return 1;
    }

    decimal_to_base2r(number, r, buffer, &index);
    result(buffer, r, index);


    return 0;
}