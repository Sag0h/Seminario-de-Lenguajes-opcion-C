#include "ejer10.h"
#include <stdio.h>
#include <string.h>

int ver_string(char *str){
    int cont = 0;
    char *saveptr;
    char *p = strtok_r(str, " ", &saveptr);
    while(p != NULL){
        if(es_palindromo(p)){
            cont++;
        }
        p = strtok_r(NULL, " ", &saveptr);
    }
    return cont;
}

void contar_capicua(char *str){
    int cont = 0;
    int linea = 1;

    char *p_aux; 

    char *p;
    p = strtok_r(str, "\n", &p_aux);
    while(p != NULL){
        cont = ver_string(p);
        printf("Linea %d -> %d.\n", linea, cont);
        linea++;
        p = strtok_r(NULL, "\n", &p_aux);
    }    
}


int main(int argc, char const *argv[]){

    char text[] = "Hola mundo\nMe llamo anna\nVivo en neuquen y nunca me iria de neuquen";

    contar_capicua(text);

    return 0;
}