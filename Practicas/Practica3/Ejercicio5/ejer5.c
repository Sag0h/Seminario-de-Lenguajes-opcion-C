#include <stdio.h>

void concat(const int dimL, int a1[], int a2[], int a3[]) {
    for( int i = 0; i < dimL; i++){
        a3[i] = a1[i] + a2[i];
        printf("%d\n",a3[i]);
    }
}

int main(int argc, char const *argv[]) {
    int dimL = 3;
    int arr1[ ] = { 23, 2, 5};
    int arr2[ ] = { 3, 2, 6};
    int arr3[ dimL ];
    concat(dimL, arr1, arr2, arr3);
    return 0;
}
