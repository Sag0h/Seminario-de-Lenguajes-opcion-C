#include <stdio.h>
#include <stdlib.h>
#define cuadrado(x) x*x // lo correcto seria ((x)*(x))

int main(int argc, char const *argv[]){
    int x = atoi(argv[1]); // atoi convierte de string a int
    printf("El argumento en la posicion 1 es: %d\n",x);
    printf("El cuadrado de %d+1 es: %d\n", x ,cuadrado(x+1));
    return 0;
}

// IMPRIME MAL PORQUE LA MACRO HACE (X + 1 * 1 + X)
// EJEMPLO: 5 + 1 * 1 + 5 = 5 + 1 + 5 = 11.
// Multiplica los 1 y suma eso a los 5. en vez de hacer (x+1)*(x+1)
// Que seria : 6 * 6 