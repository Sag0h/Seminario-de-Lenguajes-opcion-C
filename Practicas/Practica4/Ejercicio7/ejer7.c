#include <stdio.h>

struct {
    int a;
    char b;
}test;

int main()
{
    printf("sizeof(struct)= %ld, sizeof(int)= %ld, sizeof(char)= %ld\n", sizeof(test), sizeof(int), sizeof(char));
    return 0;
}


// a)- no sé
// b)- no sé
