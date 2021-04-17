#include <stdio.h>

#define MIN(a,b)(a > b) ? b : a
#define MAX(a,b)(a > b) ? a : b

int main(int argc, char const *argv[]){   
    int a, b;
    printf("Ingrese un valor entero para a y b (a b):");
    scanf("%d %d", &a, &b);
    printf("El valor minimo es: %d\n", MIN(a++,b++)); // se suma y luego hace la macro
    printf("El valor maximo es: %d\n", MAX(a++,b++));
    return 0;
}

