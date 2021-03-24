/*13. Escriba una función que reciba un entero y devuelva su factorial. */ 
#include <stdio.h>

int getFactorial(int x){
    int aux = 1;
    for(;x > 1;x--){
        aux*=x;
    }

    return aux;
}

int main()
{
    int n = 2;
    printf("Factorial de %d: %d\n", n, getFactorial(n));
    return 0;
}
