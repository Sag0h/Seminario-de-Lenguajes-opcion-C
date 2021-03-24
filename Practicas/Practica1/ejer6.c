#include <stdio.h>

char getChar(int x){
    if(x >= 0 && x <= 255){
        return (char)x;
    }
    printf("NOT A CHAR"); 
    return '\0';
}

int main(){
    printf("El caracter ASCII es: " );
    printf("%c \n",getChar(44));
    return 0;
}

