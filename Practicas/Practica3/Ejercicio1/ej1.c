#include <stdio.h>
#include <string.h>
/*1. Escriba un programa que implemente la función:
 * void convertir(int, char[ ] s, int b);
 *(a) La función debe convertir el entero i , en el string s en su representación en base b .
 *(b) La base debe ser mayor que 1 y menor que 37 dado que iría de base-2 hasta base-36, que usaría los dígitos: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ
 *(c) Implemente la función considerando que i puede ser negativo, y se empleará el mismo símbolo ( - ) para su representación en base- b .
*/ 

void invertir(char s[]) {
    // 23A5 
    char aux;
    int i = 0;
    int j = strlen(s) - 1;
    for (; i < j ; i++, j--) {
        aux = s[i];
        s[i] =  s[j];
        s[j] = aux;
    }
}

void convertir(int n, char s[], int b) {
    char *letras = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int res;
    int negativo = n < 0;
    int pos = 0;
    if( negativo ){
        n = n * -1;
    }
    do {
        res = n % b;
        s[pos] = letras[res];
        pos++;
        
        n /= b;
    } while ( n != 0);
    if(negativo ) {
        s[pos] = '-';
        pos++;
    }
    
    s[pos] = 0;

    invertir(s);
}

