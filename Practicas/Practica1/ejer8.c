/*8. Escriba una función que realice la suma de los primeros n números naturales pares. El
número n se recibe como parámetro.
(a) Escriba un programa que imprima la suma de los primeros 250 números pares. (invoque
a la función anterior)*/

#include <stdio.h>

int sumar(int n){
    int aux=0;
    for(; n>0; n--){
        aux += n;
    }
    return aux;
}

int main(){
    
    printf("La suma de los primeros 250 numeros naturales es: %d\n", sumar(250));

    return 0;
}
