/*7. Escriba una función que reciba dos enteros sin signo y retorne la división entre el mayor de
ellos y el menor.*/

#include <stdio.h>

float divMaxbyMin(unsigned int a, unsigned int b){
    float result = (a >= b) ? (float)a/b : (float)b/a;
    return result;
}

int main()
{
    printf("El resultado de la division es: %.2f\n", divMaxbyMin(15,2));
    return 0;
}
