#ifndef GLIST_H
#define GLIST_H

#include <stdlib.h>

typedef struct nodo_generico{
    void * elem;
    size_t size; // para guardar el tamaño del tipo de dato apuntado ¿?
    // void (*f)(void *, size_t); --> funcion para imprimir el tipo de dato
    struct nodo_generico * next;
} t_nodo_generico;

typedef t_nodo_generico *T_lista_generica;

//inicializa el puntero en NULL
void lista_generica_inicializar(T_lista_generica *lista);

//libera la memoria ocupada por la lista y asigna NULL al puntero
void lista_generica_destruir(T_lista_generica * lista);

//devuelve 0 si la lista está vacía u otro valor si tiene elementos
int lista_generica_esta_vacia(T_lista_generica lista);

// aloca memoria para un nuevo nodo, aloca memoria para el nuevo elemento y agrega el elemento 
int lista_generica_agregar_adelante(T_lista_generica *lista, void *elem, size_t size);

// busca *elem en la lista, lo elimina y realoca memoria para la lista. 
// (no libera la memoria del elemento eliminado)
void *lista_generica_eliminar_elemento(T_lista_generica *lista, void *elem);

// retorna verdadero (!= 0) si existe el elemento, o falso (0) en caso contrario
int lista_generica_existe_elemento(T_lista_generica lista, void *elem);

#endif





