#include <stdio.h>

char prueba(){
    return 'a' + 1;
}

int main(){
    int x = prueba(); //se agregan ceros
    printf("%c\n", prueba()); //se trunca el valor
    //casting implicito 
    return(0); 
}