// Ejercicio 12.
// Escriba una función que reciba dos enteros sin signo y devuelva el promedio

#include <stdio.h>

float promedio(unsigned int a,unsigned int b){
    return (a + b) / 2.0;
}


int main(){
    printf("%.2f\n",promedio(9,10));
    return 0;
}
