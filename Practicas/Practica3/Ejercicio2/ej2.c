#include <stdio.h>

int main(int argc, char const *argv[]) {
    char *arr1 = "Hola mundo";
    char arr2[20];
    printf(" %d\n ", sizeof(arr1)); //tamaño de un puntero
    printf(" %d\n", sizeof(arr2));  // tamaño del str
    return 0;
}

