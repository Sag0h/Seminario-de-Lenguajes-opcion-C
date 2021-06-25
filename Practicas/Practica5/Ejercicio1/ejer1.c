/* Escriba un programa que reciba como parámetros al main nombres de archivos. Para cada
archivo recibido, deberá abrirlo y leer cada carácter en él e imprimirlo en stdout. Utilice
las funciones fgetc, fputc. */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    FILE *act;
    int c;
    for(int i = 1; i < argc; i++){
        act = fopen(argv[i], "r");
        c = fgetc(act);
        while(c != EOF){
            putchar(c);
            c = fgetc(act);
        }
        putchar('\n');
        fclose(act);
    }
    return 0;
}
