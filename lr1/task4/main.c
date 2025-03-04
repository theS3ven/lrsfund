#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "states.h"
#include "handlers.c"

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return NULL;
    return dot + 1;
}

char* get_flag(char *flag){
    int i = 1, j = 0, len = strlen(flag) - 1;
    char* result = malloc(len);
    if(flag[1] == 'n'){
        i++;
    }
    for(;i < len + 1; i++){

        result[j++] = flag[i];
    }
    return result;

}

int main(int argc, char **argv){
    char* endptr;
    int count = 0, prefix = 0;
    if(argc < 3){
        fprintf(stderr, "Call: %s -flag(/flag) file\n", argv[0]);
        return 1;
    }
    char* flag = argv[1];
    if(flag[0] != '-' && flag[0] != '/'){
        fprintf(stderr, "flag %c must be started with '-' or '/'\n", flag[0]);
        return 1;
    }
    char* file_name = argv[2];
    if(file_name){  // Проверка, существует ли файл
        if(fopen(file_name, "r") == NULL || get_filename_ext(file_name) == NULL){
            perror("file cannot be open\n");
            abort();
        }
    }
    char* catch_flag;
    catch_flag = get_flag(flag);
    if(strlen(catch_flag) != 1){
        fprintf(stderr, "Error flag length, your flag was = %s\n", catch_flag);
        abort();
    }

    void(*handler[4])(const char*, const char*) = {
        handleOptD,
        handleOptI,
        handleOptS,
        handleOptA
    };
    char* new_path;
    if(flag[1] == 'n'){
        new_path = argv[3];
        if(fopen(new_path, "r") == NULL || get_filename_ext(new_path) == NULL){
            perror("file cannot be open\n");
            abort();
        }
    }else{
        if(argc > 3){
            fprintf(stderr, "Too many args\n");
            abort();
        }
        size_t len_file = strlen(file_name);
        new_path = malloc(len_file + 5);  // "out_" = 4 символа + '0'
        if(!new_path){
            fprintf(stderr, "malloc() failed\n");
            abort();
        }
        memcpy(new_path, "out_", 4);
        memcpy(new_path + 4, file_name, len_file + 1);
        printf("path = %s\n", new_path);
    }
        switch (catch_flag[0]) {
        case 'd':{
            handleOptD(file_name, new_path);
            break;
        }
        case 'i':{
            handleOptI(file_name, new_path);
            break;
        }
        case 's':{
            handleOptS(file_name, new_path);
            break;
        }
        case 'a':{
            handleOptA(file_name, new_path);
            break;
        }
        default:{
            fprintf(stderr, "Error flag\n");
            return s_ERROR_DATA;
        }
    }
    char buf_file_name[PATH_MAX];
    char buf_new_path[PATH_MAX];
    char *old = realpath(file_name, buf_file_name);
    char *new = realpath(new_path, buf_new_path);
    if(strcmp(old, new) == 0){
        printf("AHUEL?\n");
        abort();
    }
    printf("old path = %s, new path = %s\n", old, new);
    if(flag[1] != 'n'){
        free(new_path);
    }
    free(catch_flag);
    return 0;
}