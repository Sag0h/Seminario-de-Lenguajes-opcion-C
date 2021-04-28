#include <stdio.h>

char enesima_letra(int i) {
    return 96 + i;
}

int main() {
    for (int i = 1; i < 27; i++) {
        printf("La letra numero %d es %c\n", i, enesima_letra(i));
    }
}