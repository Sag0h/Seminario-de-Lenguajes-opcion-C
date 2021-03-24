/* 14. Escriba una función que reciba dos enteros y devuelva el menor de ellos. Realizarlo utilizando
una sola sentencia dentro de la función. */ 

#include <stdio.h>

int getMin(int a, int b){
    
    return (a > b) ? b : a;
}

int main(){
    
    printf("Valor minimo: %d\n", getMin(5,5));
    return 0;
}
