/* Dada una estructura como la siguiente:

struct {
    char apellido[100];
    char nombre[100];
    int edad;
}

(a) Escriba un programa que reciba como parámetro el nombre de un archivo, lo cree y
escriba en él registros que se irán leyendo desde la entrada estándar. Utilice la función
fwrite.

(b) Escriba un programa que reciba como parámetro el nombre de un archivo creado en el
punto anterior e imprima su contenido. Utilice la función fread.

(c) Analice qué sucede si los campos apellido y nombre son punteros a char.

(d) Busque una alternativa para almacenarlos. 
*/ 

#include <stdlib.h>
#include <stdio.h>
#include "ejer5.h"

int main(int argc, char const *argv[]) {
    FILE *act = fopen(argv[1], "r");
    type_persona p;
    int cant;
    cant = fread(&p, sizeof(type_persona), 1, act);
    while(cant > 0){
        printf("%s %s %d\n", p.apellido, p.nombre, p.edad);
        cant = fread(&p, sizeof(type_persona), 1, act);
    }
    fclose(act);
    return 0;
}
