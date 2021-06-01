/* Escriba una función que reciba una variable de tipo puntero a entero por referencia y aloque
la memoria necesaria para alojar un entero */

#include <stdlib.h>

void alloc_int(int **p){
    *p = malloc(sizeof(int));
}