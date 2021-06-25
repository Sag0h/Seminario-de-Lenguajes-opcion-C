/* Modifique el programa anterior para que en vez de escribir en stdout, escriba el resultado
en el último archivo recibido como parámetro. Nota: deberá recibir al menos dos parámetros
el main.*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    if(argc >= 2){
        FILE *act, *last;
        char c;
        int cant;
        for(int i = 1; i < (argc-1); i++){
            last = fopen(argv[argc-1], "a");
            act = fopen(argv[i], "r");
            cant = fread(&c, sizeof(char), 1, act);

            while(cant > 0){
                fwrite(&c, sizeof(char), 1, last);
                cant = fread(&c, sizeof(char), 1, act);
            }
            fputc('\n', last);
            fclose(act);
            fclose(last);
        }
        puts("Termino correctamente.");
    }else
        puts("Cantidad de argumentos invalida.");      
    return 0;
}
