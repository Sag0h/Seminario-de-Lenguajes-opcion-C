/*9. Escriba una función que dado un carácter devuelva si es un dígito o no.*/

#include <stdio.h>

int isDig(char x){
    return (x >= '0' && x <= '9');
}


int main(){
    printf( isDig('5') ? " Si, es un digito\n" : " No, no es un digito\n" );
    return 0;
}
