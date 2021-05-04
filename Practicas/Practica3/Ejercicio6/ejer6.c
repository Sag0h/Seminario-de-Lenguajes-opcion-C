#include <stdio.h>
#include <string.h>

void inv_print_rec(int act ,const char str[]){ 
    if( str[act] != '\0') {   
        act++;   
        inv_print_rec(act, str);
        printf("%c", str[--act]);
    }
}

void inv_print(const char str[]){ 
    int i = strlen(str);
    while( i >= 0){
        printf("%c", str[i]);
        i--;
    }
    printf("%c", '\n');
}

int main(int argc, char const *argv[]){
    char str[] = "Hola";
    inv_print_rec(0, str);
    printf("%c", '\n');
    inv_print(str);
    return 0;
}
