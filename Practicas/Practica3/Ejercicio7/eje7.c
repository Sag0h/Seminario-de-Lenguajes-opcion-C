#include <stdio.h>


int cantPalabras(char str[]) {
    int i = 0;
    int letras;
    int cant = 0;
    while(str[i] != 0) {
        letras = 0;
        while(((str[i]>= 'a')&&(str[i]<= 'z')) || ((str[i] >= 'A') && (str[i]<= 'Z'))) { 
            letras++;
            i++;
        }
        if(letras > 0){
            cant++;
        }
        if(str[i] != 0){
            i++;
        }
    }
    return cant;
}

int main(int argc, char const *argv[]) {
    char str[] = " hola ";
    char str1[] = "Hola Mundo";
    char str2[] = " Hola Como Estan? ";
    int cant1 = cantPalabras(str);
    int cant2 = cantPalabras(str1);
    int cant3 = cantPalabras(str2);

    printf("Cantidad palabras de str = %d\n", cant1);
    printf("Cantidad palabras de str1 = %d\n", cant2);
    printf("Cantidad palabras de str2 = %d\n", cant3);
    return 0;
}
