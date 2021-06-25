#include <stdio.h>
#include "int_cola_t.h"

int main() {
    int_colad_t cola1, cola2;
    int_colad_nuevo(&cola1);
    int_colad_nuevo(&cola2);
    for (int i = 0; i < 10; i++) {
        int_colad_insertar(&cola1, i);
        int_colad_agregar(&cola2, i);
    }

    printf("Un 0 de cola 1: %d\n", int_colad_ultimo(&cola1));
    printf("Un 9 de cola 2: %d\n", int_colad_ultimo(&cola2));

    while (!int_colad_vacio(cola1)) {
        printf("Números del 9 al 1: %d\n", int_colad_primero(&cola1));
    }

    int_colad_eliminar(&cola1);
    int_colad_eliminar(&cola2);
}