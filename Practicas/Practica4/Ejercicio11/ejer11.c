#include "generic_list.h"
#include <stdio.h>

/*
void mal_uso(list_t *list) {
    int i, arr_int[10] = {10, 21, 31, 42, 52, 62, -10, 2, 5, 6};
    *list = list_init();
    for(i = 0; i < 10; i++){
        list_append(list, &arr_int[i], sizeof(int));
    }
    for(i = 0; i < 10; i++){
        void *aux = delete_element(list, &arr_int[i]);
        free(aux);
    }
    list_destroy(list);
}
a). ni idea.
b). ni idea.
c). supongo que cuando el dato es un struct y queremos buscar por campo.
*/

int main(int argc, char const *argv[]) {
    
    list_t list = list_init();
    int data;
    if(is_empty(list)){
        puts("La lista esta vacia.");        
        data = 19;
        list_append(&list, &data, sizeof(int));
    }
    if(!is_empty(list)){
        puts("Hay al menos un elemento");
        if(search_element(list, &data)){
            puts("Encontro el dato.");
            void* aux = delete_element(&list, &data);
            printf("Se elimino el dato -> %d\n", data);
            free(aux);
        };
    }
    list_destroy(&list);
    puts("Se elimino la lista.");

    mal_uso(&list);

    return 0;
}
