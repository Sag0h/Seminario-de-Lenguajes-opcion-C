#include "ejer10.h"
#include <string.h>
#include <stdio.h>

int palabras_capicua(const size_t strlen,const char *str){
    int cont = 0;
    int pal_act = 0;
    char aux[strlen];
    char *p_aux = aux;
    const char *p;
    for(p = str; *p != 0; p++){
        if(((*p >= 65) && (*p <= 90)) || ((*p >= 97) && (*p <= 122))){
            pal_act++;
            *p_aux = *p; 
            p_aux++;
            *p_aux = 0;
        }else{
            p_aux = aux;
            if(pal_act != 0){
                if(es_palindromo(p_aux)){
                    cont++;
                }
            }
            aux[0]= 0;
            pal_act = 0;
        }
    }

    return cont;
}


int main(int argc, char const *argv[]){
    char str[] = "anna y neuquen son palabras capicua, \"y\" tambien porque tiene una sola letra.";
    int cont = palabras_capicua(strlen(str),str);

    printf("Cantidad de palabras capicuas en \"%s\" -> %d\n", str, cont);
    return 0;
}

#include "ejer10.c"