/*
Reescriba los ejercicios 1 y 2 empleando las funciones fread y fwrite. Analice cómo sería
reescribir los ejercicios con las funciones de bajo nivel read y write, empleando:
(a) Buffer de 1 byte.
(b) Buffer de 1024 bytes.
(c) Buffer de 4096 bytes.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    FILE *act;
    int c , cant;

    for(int i = 1; i < argc; i++){
        act = fopen(argv[i], "r");
        cant = fread(&c, sizeof(char), 1, act);
        while(cant > 0){
            putchar(c);
            cant = fread(&c, sizeof(char), 1, act);
        }
        putchar('\n');
        fclose(act);
    }
    return 0;
}


