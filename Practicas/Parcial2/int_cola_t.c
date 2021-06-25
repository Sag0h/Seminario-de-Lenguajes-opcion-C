#include "int_cola_t.h"
#include <stdlib.h>

void int_colad_nuevo(int_colad_t *cola) {
    *cola = NULL;   
}

int int_colad_agregar(int_colad_t *cola, int dato) {
    int_colad_t aux = malloc(sizeof(nodo_t));

    aux->dato = dato;

    aux->siguiente = NULL;

    if(*cola != NULL){
        int_colad_t act = *cola;
        while(act->siguiente != NULL){
            act = act->siguiente;
        }
        act->siguiente = aux;
    }else{
        *cola = aux;
    }
    return 0;
}

int int_colad_insertar(int_colad_t *cola, int dato) {
    int_colad_t aux = malloc(sizeof(nodo_t)); // new(aux);
    if(aux == NULL) return -1; // si no pudo alocar devolvio null en aux, y salgo con error -1
    
    aux->dato = dato;

    aux->siguiente = *cola; // aux^.sig = l;
    *cola = aux; // l = aux;
    
    return 0;
}

int int_colad_primero(int_colad_t *cola) {
    int num = -1;
    if(*cola != NULL){
        int_colad_t aux = (*cola);
        num = (*cola)->dato;
        *cola = (*cola)->siguiente;
        free(aux);
    }
    return num;
}

int int_colad_ultimo(int_colad_t *cola) {
    if(*cola != NULL){
        int_colad_t aux = *cola;
    
        while(aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        int num = aux->dato;
        free(aux);
        
        return num;

    }
    return -1;
}

int int_colad_vacio(int_colad_t cola) {
    return (cola == NULL);
}

void int_colad_eliminar(int_colad_t *cola){
    *cola = NULL;
}
