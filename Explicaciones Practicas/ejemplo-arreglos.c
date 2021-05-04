#include <stdio.h>

int funcion(int a[], int b[5], int *c) {
    printf("a = %ld, b = %ld, c = %ld\n", sizeof(a), sizeof(b), sizeof(c));
    return 0;
}

void imprime(int *arr, int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%d, ", arr[i]);
    }
    putchar('\n');
}

int main() {
    int x[25];
    int y[20];
    int z[10];
    printf("x = %ld, y = %ld, z = %ld\n", sizeof(x), sizeof(y), sizeof(z));
    funcion(x,y,z);
    //

    int arr[5] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    imprime(arr, sizeof(arr) / sizeof(int));
    imprime(arr2, sizeof(arr) / sizeof(int));
    return 0;
}

//la funcion imprime el tamaño de un puntero a integer

