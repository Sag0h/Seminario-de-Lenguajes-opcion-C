#include "glist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//inicializa el puntero en NULL
void lista_generica_inicializar(T_lista_generica *lista){
    *lista = NULL;
}

//libera la memoria ocupada por la lista y asigna NULL al puntero
void lista_generica_destruir(T_lista_generica * lista){
    if (*lista != NULL){
        // *lista = realloc(*lista, 0); //libera el espacio apuntado por lista y devuelve NULL
        free(*lista);
        *lista = NULL;
    }
}

//devuelve 0 si la lista  tiene elementos y un valor distinto de 0 si esta vacia
int lista_generica_esta_vacia(T_lista_generica lista){
    return (lista == NULL);
}

// aloca memoria para un nuevo nodo, aloca memoria para el nuevo elemento y agrega el elemento 
int lista_generica_agregar_adelante(T_lista_generica *lista, void *elem, size_t elem_size){
    t_nodo_generico *aux;
    aux = malloc(sizeof(t_nodo_generico));
    if (aux == NULL){
        return -1;
    }
    aux -> elem = malloc(elem_size);
    if(aux -> elem == NULL) {
        free(aux);
        return -2;
    }  
    memcpy(aux->elem, elem, elem_size);
    aux -> size = elem_size;
    aux -> next = *lista;
    *lista = aux;

    return 0;    
}

// busca *elem en la lista (que ya sabe que existe)
// elimina el nodo de la lista liberando la memoria y retorna el elemento. (void *)
// (no libera la memoria del elemento eliminado)
void *lista_generica_eliminar_elemento(T_lista_generica *lista, void *elem){
    t_nodo_generico *act = *lista;
    t_nodo_generico *prev = NULL;
    void * ret;
    while ( (act != NULL) && (memcmp(act->elem, elem, act->size)) ){
        prev = act;
        act = act-> next;
    }
    if (prev == NULL){
        *lista = act -> next;
    }
    else{
        prev-> next = act-> next;
    }
    ret = act->elem;
    free(act);
    return ret;
}

// retorna verdadero (!= 0) si existe el elemento, o falso (0) en caso contrario
int lista_generica_existe_elemento(T_lista_generica lista, void *elem){
    while( (lista != NULL) && (memcmp(lista->elem, elem, lista -> size)) ){
        lista = lista -> next;
    }
    if (lista != NULL) return 1;
    return 0;        
}



