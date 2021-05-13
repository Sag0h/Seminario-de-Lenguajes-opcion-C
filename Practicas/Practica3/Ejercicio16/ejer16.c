#include "/home/sagoh/Facultad/Seminario-C/Seminario-de-Lenguajes-opcion-C/Practicas/Practica3/Ejercicio1/ejer1.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    char conversion[1024];
    if(argc == 3) {
        convertir(atoi(argv[1]), conversion, atoi(argv[2]));
        puts(conversion);
        return 0;
    }else{
        return 1;
    }
}
