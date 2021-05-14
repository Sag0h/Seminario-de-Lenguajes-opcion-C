#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    // arreglar: tener variables para operacion y flag para i. si sale h imprimir ayuda y salir.
    int i;
    int flag = 0;
    int ok = 1; // flag por si no se pasaron parametros para los numeros
    char op;
    int num1, num2;
    for(i = 1; i < argc; i++) {
        if(!strcmp(argv[i], "-h")){
            puts("El programa imprime el resultado de enviar una operación y sus correspondientes parámetros. El resultado será impreso en pantalla.");
            puts("\nArgumentos:");
            puts("\t-s: suma los siguientes 2 parámetros.");
            puts("\t-r: resta los siguientes 2 parámetros.");
            puts("\t-d: divide los siguientes 2 parámetros.");
            puts("\t-m: multiplica los siguientes 2 parámetros.");
            puts("\t-i: imprime todos los parámetros recibidos.");
            puts("\t-h: imprime un texto de ayuda.");
            return 0;
        }else{ 
            if(!strcmp(argv[i], "-i")) flag++;
            else if(!strcmp(argv[i], "-s")) op = 's';
            else if(!strcmp(argv[i], "-r")) op = 'r';
            else if(!strcmp(argv[i], "-d")) op = 'd';
            else if(!strcmp(argv[i], "-m")) op = 'm';
            else op = 0;

            if(op != 0 && strcmp(argv[i], "-i")){
                if(((i+2) < argc) && (strcmp(argv[i+1], "-i")) && (strcmp(argv[i+2], "-i"))){
                    /* SE PUEDE HACER ESTO EN LAS SIGUIENTES DOS ITERACIONES DEL FOR \
                     Y COMPRUEBA EL CASO DE QUE PONGAN OTRA COSA ADEMAS DE -i QUE SEA DIFERENTE DE UN NUM.
                     */
                    num1 = atoi(argv[i+1]);
                    num2 = atoi(argv[i+2]);
                    i+=2;
                }else{
                    puts("Numeros de operandos invalido, se necesitan 2 parametros de valor \"entero\".");     
                    return -1;         
                }
            }
        }
    }     
    
    
    if(flag){
        printf("Los parametros ingresados son ");
        printf("\"-%c\" \"%d\" y \"%d\"\n", op, num1, num2);
        }
    if(ok){
        switch (op) {
        case 's':
            printf("El resultado de la suma es %d.\n",(num1 + num2)); 
            break;
        case 'r':
            printf("El resultado de la resta es %d.\n",(num1 - num2)); 
            break;
        case 'd':
            printf("El resultado de la division es %d.\n",(num1 / num2)); 
            break;
        case 'm':
            printf("El resultado de la multiplicacion es %d.\n",(num1 * num2)); 
            break;
        default:
            printf("No se ingresó un operando valido.\n");
            break;
        }
    }
    
    return 0;
}
