#include "ejer1.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char cadena[1024];
    convertir(-8, cadena, 8);
    puts(cadena);
    convertir(2000, cadena, 16);
    puts(cadena);
    return 0;
}
