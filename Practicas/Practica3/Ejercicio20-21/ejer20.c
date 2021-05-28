#include <stdlib.h>
#include <stdio.h>

char *crear_pila(int *dim){
    *dim = 0;
    return NULL;
}

void destruir_pila(char *p){
    free(p);
}

char *apilar(char *p, int *dim, char c){
    if(*dim == 0){
        p = malloc(sizeof(char) * (++(*dim)));
        p[*dim] = c;
    }else{
        p = realloc(p, ++(*dim));
        p[*dim] = c;
    }
    return p;
}

char *desapilar(char *p, int *dim, char *c){
    *c = p[*dim];
    p = realloc(p, --(*dim));
    if(*dim == 0){
        p = NULL;
    }
    return p;
}

int main(int argc, char const *argv[]){
    int dim;
    char *p = crear_pila(&dim);
    
    puts("Ingrese un texto: ");
    char aux = getchar();
    while(aux != EOF){
        p = apilar(p, &dim, aux);
        aux = getchar();
    }
    puts("");
    while(p != NULL){
        p = desapilar(p, &dim, &aux);
        printf("%c", aux);
    }
    puts("");
    destruir_pila(p);

    return 0;
}
