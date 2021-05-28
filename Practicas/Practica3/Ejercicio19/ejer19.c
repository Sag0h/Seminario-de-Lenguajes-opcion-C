#include <stdlib.h>

int *change_dim(int* v, int n){
    return realloc(v, n);
}