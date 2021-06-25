#ifndef INT_COLA_T_H
#define INT_COLA_T_H

typedef struct nodo{
    int dato;
    struct nodo *siguiente;
}nodo_t;

typedef nodo_t *int_colad_t ;

void int_colad_nuevo(int_colad_t *cola);

int int_colad_agregar(int_colad_t *cola, int dato);

int int_colad_insertar(int_colad_t *cola, int dato);

int int_colad_primero(int_colad_t *cola);

int int_colad_ultimo(int_colad_t *cola);

int int_colad_vacio(int_colad_t cola);

void int_colad_eliminar(int_colad_t *cola);

#endif