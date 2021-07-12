#ifndef STR_VECTOR_T_H
#define STR_VECTOR_T_H 1

enum sort_mode{SECUENCIAL, INVERTIDO, ALEATORIO};

struct str_vect{
    int dimF;
    int dimL;
    char *string;
};

typedef struct str_vect str_vector_t;

/******************************************************************
 * Macros                                                         *
 ******************************************************************/
// Retorna el elemento en la posición index del vector, si la
// posición index no existe retorna NULL.

#define str_vector_get(vector, index) {\
    ((index) < (vector->dimL)) ? (vector->string[(index)]) : NULL ;\
}

// Guarda el elemento en la posición index del vector, si el
// vector no tiene posiciones disponibles para tantos elementos,
// se lo debe agrandar para poder insertar el elemento.

// CUIDADO COMO SE USA O PUEDE QUEDAR UN VECTOR CON HUECOS, POR LA FORMA EN QUE SE IMPLEMENTO EL VECTOR, DIML MARCA CANTIDAD DE ELEMENTOS SECUENCIALES
// CUIDADO: USAR UN INDICE MUCHO MAYOR A DIML DEJA UN HUECO ENTRE LA DIML Y EL INDEX 
// CUIDADO USAR ESTA MACRO PISA LOS ELEMENTOS SI EL INDICE ESTA ENTRE LA DIM LOGICA.

#define str_vector_set(vector, index, elemento) {\
    if((index) > (vector->dimL)){\
        (vector->dimL) = (index);\
        (vector->dimF) = (index);\
        (vector->string) = realloc((vector->string), (sizeof(char *) * (vector->dimL)));\
        (vector->string[(index)] = (elemento);\
    }else (vector->string[(index)]) = (elemento);\
}

/******************************************************************
* Funciones                                                       *
******************************************************************/

/**
 * Retorna un vector vacío.
 */
str_vector_t str_vector_new();

/**
 * Agrega un nuevo elemento al vector. La cadena no debe copiarse
 * sino que se almacena el puntero.
 * Si no hay espacio alocado para el nuevo elemento es necesario
 * agrandar el vector.
 */
void str_vector_append(str_vector_t *vector, char *string);

/**
 * Agrega un nuevo elemento al vector siguiendo el orden especificado
 * por `mode` (excepto el modo random o aleatorio). La cadena no debe
 * copiarse sino que se almacena el puntero.
 * Si no hay espacio alocado para el nuevo elemento es necesario
 * agrandar el vector.
 */
void str_vector_append_sorted(str_vector_t *vector, char *string, enum sort_mode mode);

/**
 * Redimensiona el vector para contener `elements` elementos.
 * Si el vector tiene más de `elements` elementos también
 * cambia el tamaño lógico del vector para que sea igual a
 * `elements`.
 */
void str_vector_resize(str_vector_t *vector, unsigned elements);

/**
 * Ordena el vector de acuerdo a el modo elegido.
 */
void str_vector_sort(str_vector_t *vector, enum sort_mode mode);

/**
 * Libera la memoria alocada para el vector.
 */
void str_vector_free(str_vector_t *vector);

#endif
