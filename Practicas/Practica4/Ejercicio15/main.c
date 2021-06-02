#include <stdio.h>

extern int num1;
extern int num2;
extern int num3;

int main(int argc, char const *argv[]){
    printf("%d\n", num1);
    printf("%d\n", num2);
    printf("%d\n", num3);
    return 0;
}
