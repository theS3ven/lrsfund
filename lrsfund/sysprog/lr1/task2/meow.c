#include <stdio.h>
#include <stdlib.h>

#define MEOW 0x52

int main(){
    FILE* file = NULL;
    file = fopen("xor_1.bin", "wb");
    srand(52);
    size_t cnt = 0;
    for(int i = 0; i < 1000; i++){
        unsigned int ans = rand();
        if ((ans & MEOW) == MEOW){
            cnt++;
        }
        fwrite(&ans, sizeof(ans), 1, file);
    }
    fprintf(stdout, "count = %zu\n", cnt);
    fclose(file);
    return 0;
}