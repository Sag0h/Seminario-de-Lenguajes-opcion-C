#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#include <stdlib.h>

typedef struct node {
    void *data;
    size_t size;
//    void (*f)(void *, size_t); // --> funcion para imprimir el tipo de dato
    struct node *next;
}node_t;

typedef node_t *list_t;

list_t list_init(); //init list on NULL

void list_destroy(list_t *l);

int is_empty(list_t l);

int list_append(list_t *l, void* data, size_t d_size); // agrega adelante
//retorna 0 si se agrego correctamente, -1 o -2 si hubo errores al alocar memoria

void *delete_element(list_t *l, void* data);

int search_element(list_t l, void* data);

#endif