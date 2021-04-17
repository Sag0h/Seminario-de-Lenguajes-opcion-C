#include <stdio.h>

#define macro1(expr) printf(#expr "= %g\n", expr);
#define macro2(uno, dos) uno ## dos

int main(int argc, char const *argv[]){
    macro1(((2.0 + 3.0) * 4));
    printf("%d\n",macro2(2, 1));
    return 0;
}

//antes de probar el programa : 

//creo que macro 1, le pasas una expresion y te la imprime con formato
//creo que macro 2, te concatena dos valores, ejemplo 2 1 queda 21.

// despues de probar 

//estaba en lo correcto
//estaba en lo correcto.