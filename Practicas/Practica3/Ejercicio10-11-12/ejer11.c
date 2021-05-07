#include "ejer10.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int palabras_capicua(const char *str){
    int cont = 0;

    char aux[255];
 
    char *p_aux = aux;
    for(; *str != 0; str++){
        if(!isblank(*str)){
            *p_aux = *str; 
            p_aux++;
            *p_aux = 0;
        }else{
            p_aux = aux;
            if(es_palindromo(p_aux)){
                cont++;
            }
            aux[0]= 0;
        }
    }

    return cont;
}


int main(int argc, char const *argv[]){
    char str[] = "anna y neuquen son palabras capicua, \"y\" tambien porque tiene una sola letra.";
    int cont = palabras_capicua(str);

    printf("Cantidad de palabras capicuas en \"%s\" -> %d\n", str, cont);
    return 0;
}
