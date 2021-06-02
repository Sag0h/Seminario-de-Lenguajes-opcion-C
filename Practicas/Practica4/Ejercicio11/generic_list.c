#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "generic_list.h"

list_t list_init() {
    return (list_t) NULL;
}

void list_destroy(list_t *l) {
    if(*l != NULL){
        free(*l);
        *l = NULL;
    }
}

int is_empty(list_t l) {
    return (l == NULL);
}

int list_append(list_t *l, void* data, size_t d_size) { 
    list_t aux = malloc(sizeof(node_t)); // new(aux);
    if(aux == NULL){
        return -1; // si no pudo alocar devolvio null en aux, y salgo con error -1
    }
    aux->data = malloc(d_size); // aloco memoria para el dato.
    if(aux->data == NULL){
        free(aux); // como hubo un error libro lo alocado.
        return -2; //no pudo alocar memoria para el dato
    }
    memcpy(aux->data, data, d_size); // copio lo que esta en data en aux->data
    aux->size = d_size; // actualizo el tamaño del elemento actual
    aux->next = *l; // aux^.sig = l;
    *l = aux; // l = aux;
    return 0; //finalizo correctamente
}

void *delete_element(list_t *l, void* data){
    list_t act = *l, prev = NULL;
    void *ret;
    while((act != NULL)&&(memcmp(act->data, data, act->size))){
        prev = act;
        act = act->next;
    }
    if(prev == NULL){
        *l = act->next;
    }else{
        prev->next = act->next;
    }
    ret = act->data;
    free(act);
    return ret;
}

int search_element(list_t l, void *data){
    while( (l != NULL) && (memcmp(l->data, data, l->size)) ) {
        l = l -> next;
    }
    if(l != NULL) return 1; // 1 es true.
    return 0; // 0 es falso.
}