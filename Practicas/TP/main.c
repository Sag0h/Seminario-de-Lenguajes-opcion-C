#include "sortlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "error-sort.h"

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

#define COD_ERROR_FALTA_NOMBRE 2
#define COD_ERROR_ARG_INV 3
#define COD_ERROR_I_O_MAX 4

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
        char **arg_i,
        char **arg_o,
        int *reverse,
        int *shuffle,
        int *count
) {
    // falta contador para evitar repetidos de -i y -o
    int arg_i_c = 0;
    int arg_o_c = 0;
    *arg_i = NULL;
    *arg_o = NULL;

    for (int i = 1; i < argc; i++) {
       
        if ((!strcmp(argv[i], "-r")) || (!strcmp(argv[i], "--reverse"))) {
            *reverse = 1;
       
        } else if ((!strcmp(argv[i], "-s")) || (!strcmp(argv[i], "--shuffle"))) {
            *shuffle = 1;
       
        } else if ((!strcmp(argv[i], "-i")) || (!strcmp(argv[i], "--input"))) {
            arg_i_c++;
            if ((i + 1) < argc) {
                *arg_i = argv[i+1];
                i++;
            } else {
                puts("Error. No se ingreso nombre del archivo.");
                return COD_ERROR_FALTA_NOMBRE;
            }
            
        } else if ((!strcmp(argv[i], "-o")) || (!strcmp(argv[i], "--output"))) {
            arg_o_c++;
            if ((i + 1) < argc) {
                *arg_o = argv[i+1];
                i++;
            } else {
                puts("Error. No se ingreso nombre del archivo.");
                return COD_ERROR_FALTA_NOMBRE;
            }
        } else if(!strcmp(argv[i], "-c") || (!strcmp(argv[i], "--count"))){
            *count = 1;
        } else if (!strcmp(argv[i], "--help")){
            help();
            exit(0);
        }else {
            printf("Argumento invalido \"%s\"\n", argv[i]);
            return COD_ERROR_ARG_INV;
        }
    }

    if( (arg_i_c > 1) || (arg_o_c > 1)){
        return COD_ERROR_I_O_MAX;
    }

    return 0;
}



int main(int argc, char *argv[]){
    
    int reverse, shuffle, count;
    FILE *input, *output;
    char *arg_i; 
    char *arg_o;
    reverse = shuffle = count = 0;
    input = output = NULL;

    int error = procesar_args(argc, argv, &arg_i, &arg_o ,&reverse, &shuffle, &count);

    if (error) {
        help();
        return -1;
    }

    if ((reverse) && (shuffle)) {
        puts("Warning: no se puede usar -r --reverse y -s --shuffle a la vez.");
        help();
        return -2;
    }

  
    // Open file
    if ( (arg_i !=NULL) && (! (input = fopen(arg_i,"r")) ) ){
        output_error(stderr, -E_FILE_ERROR);
        perror(" ");
        exit(-E_FILE_ERROR);  
    }

    // Open file
    if ( (arg_o !=NULL) && (! (output = fopen(arg_o,"w")) ) ) {
        output_error(stderr, -E_FILE_ERROR);
        perror(" ");
        exit(-E_FILE_ERROR);  
    }

    if(arg_i == NULL){
        input = stdin;
        arg_i = "STDIN";
    }

    if(arg_o == NULL){
        output = stdout;
        arg_o = "STDOUT";
    }

    if(count){
        if((shuffle) || (reverse)){
            puts("Warning: se ignorarán los argumentos: \"-o , --output <archivo>, -s, --shuffle, -r, --reverse\".");
        } 
        count_function(input);
        exit(0);
    }

    // leer y ordena
    
    sort_file(input, output, reverse, shuffle);
    fclose(input);fclose(output);
}
