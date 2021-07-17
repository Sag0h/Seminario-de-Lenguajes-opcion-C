#include "str_vector_t.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    str_vector_t array = str_vector_new();
    str_vector_resize(&array, 10);
    FILE *in, *o;

    in = stdin;
    o = stdout;

    puts("Ingresar 10 strings:");
    char line[BUFSIZ];
    while (fgets(line, BUFSIZ, in) != NULL){
        char *aux = malloc(strlen(line)+1);
        if (aux == NULL){
            fprintf(stderr, "Error alocando memoria para la linea leida.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(aux, line);
        str_vector_append(&array, aux);
    }
  

    for(int i=0; i < array.l_dim; i++){
        fputs(array.str_array[i], o);
        free(array.str_array[i]);
    }

    str_vector_free(&array);
    fclose(in); fclose(o);
    return 0;
}
