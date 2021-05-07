#include "ejer10.h"
#include <string.h>

int es_palindromo(const char *word){
    int len = strlen(word)-1; 
    int ok = 1;
    for(int i=0, j=len; ok && (i<j); i++, j--){
        ok = (word[i] == word[j]);
    }
    return ok;
}



char *encripto (char *dest, const char *src){
    for(; *src != 0; src++, dest++){
        *dest = ~*src;
    }
    *dest = '\0';
    return dest;
}
