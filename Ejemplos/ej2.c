#include <stdio.h>
#include <ctype.h>

//determinar si c es minuscula

int es_minuscula (char c){
    return islower(c);
}

int main() {
    printf(es_minuscula('d') ? "es minuscula\n" : "no es minuscula\n");
    printf(es_minuscula('4') ? "es minuscula\n" : "no es minuscula\n");
    return 0;
}
    
