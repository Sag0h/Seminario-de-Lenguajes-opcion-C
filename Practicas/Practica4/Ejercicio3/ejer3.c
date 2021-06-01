#include <stdio.h>

void initialize_int(int * num){
    *num = 0;
}

int main(int argc, char const *argv[]){
    int num;
    initialize_int(&num);
    printf("%d\n", num);
    return 0;
}
