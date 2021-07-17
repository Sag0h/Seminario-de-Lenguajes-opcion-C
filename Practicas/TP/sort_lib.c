#include "sort_lib.h"

void count_function( /*@in@*/ FILE *fpin){
    char *mem=malloc(sizeof(char)*BUFSIZ);
    int c = 0;
    while(fgets(mem, 1024, fpin) != NULL){
        c++;
    }
    printf("En el archivo de entrada hay en total %d líneas.\n", c);
    free(mem);
}



void sort_file( /*@ in @*/  FILE *fpin, 
                /*@ in @*/  FILE *fpout,   
                /*@ in @*/ int   flag_r,
                /*@ in @*/ int   flag_s
                ){
    
    str_vector_t array = str_vector_new();
    enum sort_mode mode;
    if(flag_r){
        mode = REVERSE;
    }else if(flag_s){
        mode = SHUFFLE;
    }else{
        mode = SEQUENTIAL;
    } 
    
    char line[BUFSIZ];
    while (fgets(line, BUFSIZ, fpin) != NULL){
        char *aux = malloc(strlen(line)+1);
        if (aux == NULL){
            fprintf(stderr, "Error alocando memoria para la linea leida.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(aux, line);
        //str_vector_append(&array, aux);
        str_vector_append_sorted(&array, aux, mode);
        
    }
    
 
    //str_vector_sort(&array, mode);

    
    for(int i = 0; i < array.l_dim; i++){
        fputs(array.str_array[i], fpout);
        free(array.str_array[i]);
    }

    
    str_vector_free(&array);

}
                