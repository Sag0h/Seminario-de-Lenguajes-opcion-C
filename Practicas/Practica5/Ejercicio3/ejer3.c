/* Escriba un programa que compare dos archivos e imprima la línea en que difieren. Usar
fgets. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    FILE *f1, *f2;

    f1 = fopen("texto1.txt", "r");
    f2 = fopen("texto2.txt", "r");
    char linea1[255], linea2[255];
    int pos = 1;
    int ok = 1;
    int flag = 0;
    while ((ok)&&(!flag)){
        if(fgets(linea1, 255, f1) != NULL){
            if(fgets(linea2, 255, f2) != NULL){
                if(!strcmp(linea1, linea2)){
                    pos++;
                }else flag = 1;
            }else {
                flag = 1;
                pos++;
                ok = 0;
            }
        }else{
            if(fgets(linea2, 255, f2) != NULL) {
                pos++;
                flag = 1;
            }
            ok = 0;
        }
    }
        
    if(flag) printf("Difieren en la linea: %d\n", pos);
    fclose(f1);
    fclose(f2);
    return 0;

}
