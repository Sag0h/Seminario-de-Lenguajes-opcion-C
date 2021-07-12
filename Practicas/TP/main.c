#include "str_vector_t.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
-r o --reverse
Invierte la condición de ordenación.
-s o --shuffle
Ordena de forma aleatoria (no imprime repetidos).
-i <archivo> o --input <archivo>
Lee las líneas desde el archivo indicado. Si se omite se leen desde stdin.
-o <archivo> o --output <archivo>
Escribe los resultados en el archivo indicado. Si se omite se escriben en stdout.
*/

#define COD_ERROR_FALTA_NOMBRE -2

void count_function(FILE *input){

}

void help(){
    puts("Este programa se utiliza mediante los siguientes argumentos:");
    puts("\t-r o --reverse\nInvierte la condición de ordenación.");
    puts("\t-s o --shuffle\nOrdena de forma aleatoria(no imprime repetidos).");
    puts("Si se omiten -r o -s se ordenara el archivo en el orden dado por los ASCII de sus elementos.");
    puts("\t-i <archivo> o --input <archivo>\nLee las líneas desde el archivo indicado.\nSi se omite se leen desde stdin.");
    puts("\t-o <archivo> o --output <archivo>\nEscribe los resultados en el archivo indicado.\nSi se omite se escriben en stdout.");
    puts("\t-c o --count\nCuenta la cantidad de líneas en el archivo de entrada e imprime el resultado en la salida estándar.");
}

int procesar_args(
        int argc,
        char *argv[],
        int *reverse,
        int *shuffle,
        int *count,
        FILE **input,
        FILE **output
) {
    // falta contador para evitar repetidos de -i y -o

    int i_c, o_c; // contadores para evitar repetidos -i y -o
    i_c = o_c = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-r") || strcmp(argv[i], "--reverse")) {
            *reverse = 1;
        } else if (strcmp(argv[i], "-s") || strcmp(argv[i], "--shuffle")) {
            *shuffle = 1;
        } else if (strcmp(argv[i], "-i") || strcmp(argv[i], "--input")) {
            i_c++;
            if (i + 1 < argc) {
                *input = fopen(argv[i + 1], "r");
                if(*input == NULL){
                    puts("Error al abrir, se abrira el stdin.");
                }
            } else {
                puts("Error. No se ingreso nombre del archivo.");
                return COD_ERROR_FALTA_NOMBRE;
            }
            i++;
        } else if (strcmp(argv[i], "-o") || strcmp(argv[i], "--output")) {
            o_c++;
            if (i + 1 < argc) {
                *output= fopen(argv[i + 1], "w");
                if(*output == NULL){
                    puts("Error al abrir, se abrira el stout.");
            } else {
                puts("Error. No se ingreso nombre del archivo.");
                return COD_ERROR_FALTA_NOMBRE;
            }
            i++;
        } else if(strcmp(argv[i], "-c") || strcmp(argv[i], "--count")){
            *count = 1;
        } else if (strcmp(argv[i], "--help")){
                help();
                exit(0);
        }
    }
    

    if (*input == NULL) *input = stdin;
    if (*output == NULL) *output = stdout;

    return 0;
}

int main(int argc, char *argv[]) {
    int reverse, shuffle, count;
    FILE *input, *output;
    reverse = shuffle = count = 0;
    input = output = NULL;

    int error = procesar_args(argc, argv, &reverse, &shuffle, &count ,&input, &output);

    if (error) {
        help();
        return -1;
    }

    if (reverse && shuffle) {
        help();
        return -2;
    }

    if(count){
        if(shuffle || reverse || (output != NULL)) puts("Warning: se ignorarán los argumentos: \"-o , --output <archivo>, -s, --shuffle, -r, --reverse\".");
        count_function(&input);
    }
    
    enum sort_mode mode;

    if(reverse){
        mode = INVERTIDO;
    }else if(shuffle){
        mode = ALEATORIO;
    }else mode = SECUENCIAL;

    // leer y ordenar
    str_vector_t vector = str_vector_new();
    char *str = malloc(sizeof(char) * 512);
    while(!feof(input)){
        *str = fgets(str, 512, input);
        str_vector_append_sorted(&vector, str, mode);
    }



}
