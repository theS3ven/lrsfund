#include "handlers.h"

void writeInBase(int decimal, int base, FILE* file){
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
        fprintf(file, "%c", number[i]);
    }
    fprintf(file, " ");
}

void handleOptD(const char* input_file, const char* output_file){
    FILE* from = fopen(input_file, "r");
    FILE* to = fopen(output_file, "w");
    char current;

    if(from && to){
        while((current = fgetc(from)) != EOF){
            if(current >= '0' && current <= '9' || current == '-'){
                continue;
            }else{
                fputc(current, to);
            }
        }
    }
    fclose(from);
    fclose(to);
}

void handleOptI(const char* input_file, const char* output_file){
    FILE* from = fopen(input_file, "r");
    FILE* to = fopen(output_file, "w");
    int count = 0, i = 1;
    char current;
    
    if(from && to){
        while((current = fgetc(from)) != EOF){
            if(current != '\n'){
                if((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')){
                    count++;
                }
            }else{
                fprintf(to, "%d string, letters count = %d\n", i, count);
                i++;
                count = 0;
            }

        }
    }
    fprintf(to, "%d string, letters count = %d\n", i++, count);  // Последняя строчка не обрабатывалась
    fclose(from);
    fclose(to);
}

void handleOptS(const char* input_file, const char* output_file){
    FILE* from = fopen(input_file, "r");
    FILE* to = fopen(output_file, "w");
    int count = 0, i = 1;
    char current;

    if(from && to){
        while((current = fgetc(from)) != EOF){
            if(current != '\n'){
                if((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || (current >= '0' && current <= '9') || current == ' '){
                    continue;
                }else{
                    count++;
                }
            }else{
                fprintf(to, "%d string, count non letters = %d\n", i, count);
                count = 0;
                i++;
            }
        }
    }
    fprintf(to, "%d string, count non leters = %d\n", i++, count);
    fclose(from);
    fclose(to);
}

void handleOptA(const char* input_file, const char* output_file){
    FILE* from = fopen(input_file, "r");
    FILE* to = fopen(output_file, "w");
    char current;

    if(from && to){
        while((current = fgetc(from)) != EOF){
            if(current != '\n'){
                if(current >= '0' && current <= '9'){
                    continue;
                }else{
                    int current_int = (int)current;
                    writeInBase(current_int, 16, to);
                }
            }else{
                fprintf(to, "\n");
            }
        }
    }
    fclose(from);
    fclose(to);
}