#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
    char c1[] = "Hola";
    char c2[] = "Chau";

// Siempre da distinto porque compara las posiciones de memoria.

    if(c1 == c2) {
        puts("Son iguales\n");
    }else {
        puts("Son distintas\n");
    }

// Para comparar cadenas -> hay funciones, mirar manpages -> strcmp compara strings

    strcmp(c1, c2) == 0 ? puts("Son iguales\n") : puts("Son distintas\n");

// Para copiar cadenas -> strcpy copia cadenas

    strcpy(c2, c1);

    printf("%s\n", c1);

// Mas funciones de strings en man 3 string.h


    return 0;
}
