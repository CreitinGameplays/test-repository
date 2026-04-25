#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* penis = fopen("compile.txt", "r");

    if (!penis){
        fputs("error while reading file.\n", stderr);
        return EXIT_FAILURE;
    }
    
    //int cur_char;
    //while ((cur_char = fgetc(penis)) != -1) putchar(cur_char);
    
    printf("Test: %p\n", (void *)penis);
    if (ferror(penis)) puts("fatal and criminal error");

    const char* real = "12aqui e o cara da luva de predeiro3";
    int* games = (int*)real;
    printf("Testando: %i\n", *games);

    int bosta = 0x8B40;
    printf("%d", bosta);

    return 0;
}
