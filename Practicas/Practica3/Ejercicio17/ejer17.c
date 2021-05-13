#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    
    int i;
    for(i = argc-1; i > 0; i--){

        if(!strcmp(argv[i], "-s")) printf("El resultado de la suma es %d.\n",(atoi(argv[i+1])+atoi(argv[i+2])));
        else if(!strcmp(argv[i], "-r")) printf("El resultado de la resta es %d.\n",(atoi(argv[i+1])-atoi(argv[i+2])));  
            else if(!strcmp(argv[i], "-d")) printf("El resultado de la division es %d.\n",(atoi(argv[i+1])/atoi(argv[i+2])));  
                else if(!strcmp(argv[i], "-m")) printf("El resultado de la multiplicacion es %d.\n",(atoi(argv[i+1])*atoi(argv[i+2])));  
                    else{
                        if(!strcmp(argv[i], "-i")){
                            printf("Los parametros ingresados son ");
                            int j;
                            for(j = 1; j < argc-1; j++){
                                printf("\"%s\" ", argv[j]);
                            }
                            printf("y \"%s\"\n", argv[j]);
                        }else if(!strcmp(argv[i], "-h")){
                            puts("El programa imprime el resultado de enviar una operación y sus correspondientes parámetros. El resultado será impreso en pantalla.");
                            puts("\nArgumentos:");
                            puts("\t-s: suma los siguientes 2 parámetros.");
                            puts("\t-r: resta los siguientes 2 parámetros.");
                            puts("\t-d: divide los siguientes 2 parámetros.");
                            puts("\t-m: multiplica los siguientes 2 parámetros.");
                            puts("\t-i: imprime todos los parámetros recibidos.");
                            puts("\t-h: imprime un texto de ayuda.");
                        }
                    }
    }

    return 0;
}
