/* Modifique el programa anterior para que en vez de escribir en stdout, escriba el resultado
en el último archivo recibido como parámetro. Nota: deberá recibir al menos dos parámetros
el main.*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    if(argc >= 2){
        FILE *act, *last;
        int c;
        for(int i = 1; i < (argc-1); i++){
            last = fopen(argv[argc-1], "a");
            act = fopen(argv[i], "r");
            c = fgetc(act);
            while(c != EOF){
                fputc(c, last);
                c = fgetc(act);
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
