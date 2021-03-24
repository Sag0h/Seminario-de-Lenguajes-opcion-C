/*Escriba una función que dado un carácter retorne su mayúscula, si está en minúscula y el
mismo carácter en caso contrario.*/ 

#include <stdio.h>

char toReverseCase(char x){
    if(x >= 'a' && x <= 'z'){
        x -= 32;
    }else if (x >= 'A' && x <= 'Z'){
        x += 32;
    }else{
        return 0;
    }
    return (char)x;
}


int main(){
    int aux = toReverseCase('A');
    if( aux ){
        printf("%c\n", aux);
    }else
        printf("It's not an alphabet character.\n" );

    return 0;
}
