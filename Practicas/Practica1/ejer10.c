/* 10. Escriba una función que dado un carácter devuelva si es mayúscula o minúscula. */ 

#include <stdio.h>

int isUpperOrLower(char x){
    if(x >= 'a' && x <= 'z'){
        return 1;
    }else if (x >= 'A' && x <= 'Z'){
        return 2;
    }
    return 0;
}


int main(){

    int aux = isUpperOrLower('A');
    switch (aux){
    case 1:
        printf("It's Lowercase.\n");
        break;
    case 2: 
        printf("It's Uppercase.\n");
        break;
    default:
        printf("It's not an alphabet character.\n");
        break;
    }

    return 0;
}



