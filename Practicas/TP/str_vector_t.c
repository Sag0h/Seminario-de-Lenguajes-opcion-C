#include "str_vector_t.h"


/******************************************************************
* Funciones                                                       *
******************************************************************/

/**
 * Retorna un vector vacío.
 */

str_vector_t str_vector_new(){
    str_vector_t vector;
    vector.p_dim = 0;
    vector.l_dim = 0;
    vector.str_array = NULL;
    return vector;
}

/**
 * Agrega un nuevo elemento al vector. La cadena no debe copiarse
 * sino que se almacena el puntero.
 * Si no hay espacio alocado para el nuevo elemento es necesario
 * agrandar el vector.
 */

void str_vector_append(str_vector_t *vector, char *string){
    vector->l_dim++;
    
    if(vector->p_dim < vector->l_dim){
        vector->str_array = realloc(vector->str_array , (sizeof(char *))*(vector->l_dim));
        vector->p_dim = vector->l_dim;
    }

    vector->str_array[vector->l_dim-1] = string;
}



/**
 * Agrega un nuevo elemento al vector siguiendo el orden especificado
 * por `mode` (excepto el modo random o aleatorio). La cadena no debe
 * copiarse sino que se almacena el puntero.
 * Si no hay espacio alocado para el nuevo elemento es necesario
 * agrandar el vector.
 */

void str_vector_append_sorted(str_vector_t *vector, char *string, enum sort_mode mode){

    vector->l_dim++;
    if(vector->p_dim < vector->l_dim){
        vector->str_array = realloc(vector->str_array, (sizeof(char *) * vector->l_dim));
        vector->p_dim = vector->l_dim;
    }
    
    if(mode == SHUFFLE){
        srand(time(NULL));
        int index = rand() % vector->l_dim;
        for(int i = vector->l_dim-1; i > index; i--){
            vector->str_array[i] = vector->str_array[i-1];
        }
        vector->str_array[index] = string;
    }else{
        if(vector->l_dim == 1){
            vector->str_array[vector->l_dim-1] = string;
        }else{
            int pos, res;
            if(mode == REVERSE){   

                int i = 0;
                bool found = false;

                while( i < vector->l_dim && !found){

                    if( (res = strcmp(string, vector->str_array[i])) > 0 ){
                        pos = i;
                        found = true;
                    }else i++;

                }
                if(!found) pos = vector->l_dim-1;


            }else if (mode == SEQUENTIAL){

                int i = 0;
                bool found = false;
                
                while( i < vector->l_dim && !found){
                
                    if( (res = strcmp(string, vector->str_array[i])) < 0 ){
                        pos = i;
                        found = true;
                    }else i++;
                
                }
                
                if(!found) pos = vector->l_dim-1;

            }
            
            for(int i = vector->l_dim-1; i > pos; i--){
                vector->str_array[i] = vector->str_array[i-1];
            }
            vector->str_array[pos] = string;  

        }
    }
}

/**
 * Redimensiona el vector para contener `elements` elementos.
 * Si el vector tiene más de `elements` elementos también
 * cambia el tamaño lógico del vector para que sea igual a
 * `elements`.
 */
void str_vector_resize(str_vector_t *vector, unsigned elements){
    vector->p_dim = elements;
    vector->str_array = realloc(vector->str_array, (sizeof(char *))*(vector->p_dim));
    if(vector->l_dim > vector->p_dim){
        vector->l_dim = elements;
    }
}

static void shuffle(str_vector_t *vector){
    int arreglo_aux[vector->l_dim];
    int index;
    srand(time(NULL));
    bool ok;
    for(int i=0; i < vector->l_dim; i++){
        ok = false;
        index = rand() % vector->l_dim+1;
        while(!ok){
            //compruebo que el index sea unico.
            for(int j = 0; ((j < i) && (!ok)); j++){
                if(arreglo_aux[j] == index) ok = true;
            } //compruebo que no exista antes en el vector de indices
            if(ok){ 
                index = rand() % vector->l_dim+1;                          
                ok = false;

                // si existia busco otro indice random pongo en false para que entre en el while de nuevo

            }else ok = true;    
             //si no existia el indice pongo en true para salir del while y luego lo agrego a la posicion actual.
        }
        arreglo_aux[i] = index;
    }

    str_vector_t new_vect_random = str_vector_new();
    new_vect_random.l_dim = vector->l_dim;
    new_vect_random.p_dim = vector->p_dim;

    for(int i = 0; i < vector->l_dim; i++){
        new_vect_random.str_array[i] = vector->str_array[arreglo_aux[i]];
    } 
    free(vector);
    vector = &new_vect_random;
}




static int cmpstringp_seq(const void *p1, const void *p2) {
   return strcmp(* (char * const *) p1, * (char * const *) p2);
}

static int cmpstringp_rev(const void *p1, const void *p2) {
   return !strcmp(* (char * const *) p1, * (char * const *) p2);
}


/**
 * Ordena el vector de acuerdo a el modo elegido.
 */


void str_vector_sort(str_vector_t *vector, enum sort_mode mode){
    if(mode == SHUFFLE) {
        shuffle(vector);
    }else if(mode == REVERSE) {
        qsort(vector->str_array, vector->l_dim-1, sizeof(char *), cmpstringp_rev);
    }else{
        qsort(vector->str_array, vector->l_dim-1, sizeof(char *), cmpstringp_seq);
        // Si se omiten -r o -s se ordenara el archivo en el orden dado por los ASCII de sus elementos.
    }
}

/**
 * Libera la memoria alocada para el vector.
 */
void str_vector_free(str_vector_t *vector){
    vector->p_dim = 0;
    vector->l_dim = 0;
    free(vector->str_array);
}
