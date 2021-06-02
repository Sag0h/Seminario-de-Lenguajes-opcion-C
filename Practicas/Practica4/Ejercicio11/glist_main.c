#include "glist.h"
#include <stdio.h>

/*
void mal uso(T_lista_generica * lista){
    int i, arr_int[10] = {10, 21, 31, 42, 52, 62, 10, 2, 5, 6};
    lista_generica_inicializar(lista);
    for (i=0; i<10; i++){
        lista_generica_agregar_adelante(lista, &arr_int[i]);
    }
}
*/

int main (){
    T_lista_generica lista;

    lista_generica_inicializar(&lista);
    printf("lista_generica_inicializar(&lista)\n");
    printf("lista = %p\n\n", lista);

    if (lista_generica_esta_vacia(lista)){
        printf("La lista está vacía.\n\n");
    }
    else printf("La lista tiene 1 o más elementos.\n\n");

    int i;
    for (i = 0; i < 10; i++){
        lista_generica_agregar_adelante(&lista, (void*) &i, sizeof(i));
    }

    printf("int i;\nfor (i = 0; i < 10; i++){\n   lista_generica_agregar_adelante(&lista, (void*) &i, sizeof(i));\n}\n\n");

    if (lista_generica_esta_vacia(lista)){
        printf("La lista está vacía.\n\n");
    }
    else printf("La lista tiene 1 o más elementos.\n\n");

    
    T_lista_generica aux;
    // recorre la lista imprimiendo los datos almacenados
    aux = lista;
    while(aux != NULL){
        printf(" %d ",  *(int*)(aux->elem));
        aux = aux->next;
    }

    putchar('\n');

    int elem_a_eliminar;
    void * elem_eliminado;
    for (i=0; i<10;i++){
        elem_a_eliminar = i;
        elem_eliminado = lista_generica_eliminar_elemento(&lista, (void*)&elem_a_eliminar);
        printf("Se elimino el elemento %d\n", *(int *)elem_eliminado);
        free(elem_eliminado);
        aux = lista;
        while(aux != NULL){
            printf("LISTA: ");
            printf(" %d ",  *(int*)(aux->elem));
            aux = aux->next;
            printf("lista_generica_inicializar(&lista)\n");
            printf("lista = %p\n\n", lista);
        }
        putchar('\n');
    }
    if (lista_generica_esta_vacia(lista)){
        printf("La lista está vacía.\n\n");
    }
    else printf("La lista tiene 1 o más elementos.\n\n");

    lista_generica_destruir(&lista);

    printf("lista_generica_inicializar(&lista)\n");
    printf("lista = %p\n\n", lista);

}