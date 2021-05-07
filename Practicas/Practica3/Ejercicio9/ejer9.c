#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *dest, const char *src){

    const char *punt;
    
    char *i;

    for( i = dest; *i != 0; i++)
    ;

    for( punt = src; *punt != 0; punt++, i++){
        *i = *punt;
    }
    
    *i = '\0';

    return dest;
}

int my_strcmp(const char *s1, const char *s2) {

    int ret = 0;

    while((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0') ){
        s1++;
        s2++;
    }

    if(*s1 == *s2){
        return ret;
    }else if(*s1 > *s2){
        ret++;
    }else{
        ret--;
    }

    return ret;
}

char *my_strcpy(char *dest, const char *src){

    const char *p;
    char *i;
    for ( p = src, i = dest; *p != '\0'; p++, i++){
        *i = *p;        
    }

    *i = '\0';
    
    return dest;
}

size_t my_strlen(const char *s){
    int i = 0;
    for(; *s != 0; s++){
        i++;
    }
    return i;
}
 
const char *my_strstr(const char *haystack, const char *needle) {
    int i = 0;
    while (haystack[i] != 0) {
        if (strncmp(haystack + i, needle, strlen(needle)) == 0) {
            return haystack + i;
        }
        i++;
    }
    return NULL;
}
 
int main(){
    char *cadena = "asdasdshoSadadsaholaasdad";
    printf("%s\n", my_strstr(cadena, "hola"));
}
 

int main(int argc, char const *argv[]) {
    char s1[255] = "Hola";
    char s2[255] = " abhoasdadhola";

    my_strcat(s1, s2);

    printf("%s\n", s1);

    printf("comparacion de s1 y s2: %d\n", my_strcmp(s1, s2));

    my_strcpy(s2, s1);

    printf("s2: %s\n", s2);

    my_strcat(s1, s2);

    printf("s1: %s\n", s1);

    printf("El tamaño del string s1 es: %ld\n", my_strlen(s1));

    printf("Substring \"hola\": %s\n", my_strstr(s2, "hola"));

    return 0;
}
