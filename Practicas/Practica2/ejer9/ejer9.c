#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *str = "Hello world";
    printf(" %.*s\n", 5, str);
    return 0;
}
// imprime hello_ (5)