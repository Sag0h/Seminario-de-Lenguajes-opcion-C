#include "str_vector_t.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/******************************************************************
* Funciones                                                       *
******************************************************************/

/**
 * Retorna un vector vacío.
 */

str_vector_t str_vector_new(){
    str_vector_t vector;
    vector.dimF = 0;
    vector.dimL = 0;
    vector.string = NULL;
    return vector;
}

/**
 * Agrega un nuevo elemento al vector. La cadena no debe copiarse
 * sino que se almacena el puntero.
 * Si no hay espacio alocado para el nuevo elemento es necesario
 * agrandar el vector.
 */

void str_vector_append(str_vector_t *vector, char *string){
    vector->dimL++;
    
    if(vector->dimF < vector->dimL){
        vector->string = realloc(vector->string , (sizeof(char *))*(vector->dimL));
        vector->dimF = vector->dimL;
    }

    vector->string[vector->dimL-1] = string;
}

/**
 * append invertido, agrega nuevo elemento al inicio del vector
 * se usa en str_vector_append_sorted
 */

static void str_vector_inv(str_vector_t *vector, char *string) {
    vector->dimL++;
    if(vector->dimF < vector->dimL){
        vector->string = realloc(vector->string, (sizeof(char *))*(vector->dimL));
        vector->dimF = vector->dimL;
    }
    for(int i = vector->dimL-1; i > 0; i--){
        vector->string[i] = vector->string[i-1];
    }
    vector->string[0] = string;
}


/**
 * Agrega un nuevo elemento al vector siguiendo el orden especificado
 * por `mode` (excepto el modo random o aleatorio). La cadena no debe
 * copiarse sino que se almacena el puntero.
 * Si no hay espacio alocado para el nuevo elemento es necesario
 * agrandar el vector.
 */

void str_vector_append_sorted(str_vector_t *vector, char *string, enum sort_mode mode){
    if(mode == SECUENCIAL){
        str_vector_append(&vector, &string);
    }else if(mode == INVERTIDO){
        str_vector_inv(&vector, &string);
    }
}

/**
 * Redimensiona el vector para contener `elements` elementos.
 * Si el vector tiene más de `elements` elementos también
 * cambia el tamaño lógico del vector para que sea igual a
 * `elements`.
 */
void str_vector_resize(str_vector_t *vector, unsigned elements){
    vector->dimF = elements;
    vector->string = realloc(vector->string, (sizeof(char *))*(vector->dimF));
    if(vector->dimL > vector->dimF){
        vector->dimL = elements;
    }
}

/**
 * Ordena random el vector
 */


static void random_sort(str_vector_t *vector){
    int arreglo_aux[vector->dimL];
    int index;
    
    bool ok;
    for(int i=0; i < vector->dimL; i++){
        ok = false;
        index = rand() % vector->dimL+1;
        while(!ok){
            //compruebo que el index sea unico.
            for(int j = 0; ((j < i) && (!ok)); j++){
                if(arreglo_aux[j] == index) ok = true;
            } //compruebo que no exista antes en el vector de indices
            if(ok){ 
                index = rand() % vector->dimL+1;                          
                ok = false;

                // si existia busco otro indice random \
                 pongo en false para que entre en el while de nuevo

            }else ok = true;    
             //si no existia el indice pongo en true para salir del while \
              y luego lo agrego a la posicion actual.
        }
        arreglo_aux[i] = index;
    }

    str_vector_t *new_vect_random = malloc((sizeof(char *) * vector->dimL));
    new_vect_random->dimL = vector->dimL;
    new_vect_random->dimF = vector->dimF;
    for(int i = 0; i < vector->dimL; i++){
        new_vect_random->string[i] = vector->string[arreglo_aux[i]];
    } 
    free(vector);
    vector = new_vect_random;
}

/**
 * Ordena el vector de acuerdo a el modo elegido.
 */


void str_vector_sort(str_vector_t *vector, enum sort_mode mode){
    if(mode = ALEATORIO) {
        random_sort(&vector);
    }else if(mode = INVERTIDO) {
        char *aux;
        for(int i=0, j=vector->dimL;(i<j); i++, j--){
            aux = vector->string[i];
            vector->string[i] = vector->string[j];
            vector->string[j] = aux;
        }
    }else{
        // Si se omiten -r o -s se ordenara el archivo en el orden dado por \
        los ASCII de sus elementos.
        int i, j;
        int c;
        char *clave;

        // Ordenacion por Inserción

        for (i = 1; i < vector->dimL; i++){	   
		    clave = vector->string[i];
		    j = i-1;
            c = (strcmp(vector->string[j], clave));
		    //Comparar el valor selecionado con todos los valores anteriores
		    while (j >= 0 && c >= 0){
			    //Insertar el valor donde corresponda
			    vector->string[j+1] = vector->string[j];
			    j = j-1;
                if(j >= 0) c = (strcmp(vector->string[j], clave));            
		    }
		    vector->string[j+1] = clave;
    	}    
    }
}

/**
 * Libera la memoria alocada para el vector.
 */
void str_vector_free(str_vector_t *vector){
    vector->dimF = 0;
    vector->dimL = 0;
    free(vector->string);
}
