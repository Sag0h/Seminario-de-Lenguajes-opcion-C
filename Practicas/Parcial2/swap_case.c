#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/**
 * La siguiente función recibe un string y retorna
 * un nuevo string con las mayúsculas y minúsculas
 * intercambiadas.
 * El nuevo string debe ser alocado dinámicamente.
 */

char *swap_case(char *str) {
    char *aux = malloc(sizeof(char)*strlen(str)+1);
    char *pos = aux;
    while(*str != 0){
        if(isupper(*str)){
           *pos = tolower(*str);
        }else{
           *pos = toupper(*str);
        }
        pos++;
        str++;
    }

    return aux;    
}

int main() {
    char *s;
    s = swap_case("Hola mundo!");
    puts(s); // Imprime "hOLA MUNDO!"
    free(s);
    s = swap_case("1aBc");
    puts(s); // Imprime "1AbC"
    free(s);
}