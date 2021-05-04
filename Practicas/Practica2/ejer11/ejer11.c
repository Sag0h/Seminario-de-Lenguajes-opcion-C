

//a. valor de retorno -> cantidad de valores leidos, o -1 si EOF o error.

//b.
/*

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y;
    scanf(" %d", &x);
    scanf(" %d %d",&x,&y);
    scanf(" %d%d",&x,&y);
    return 0;
}

respuesta: lee de la entrada un entero y lo guarda en x, despues lee dos enteros y los guarda en x e y
 respectivamente, luego hace lo mismo.

*/

//c.el operador de direccion & sirve de puntero a las posiciones de memoria donde estan las var
//donde se guardaran los datos leidos.

#include <stdio.h>
int main(){
    int res, dia, mes, anio;
    do {
        res = scanf(" %2d/ %2d/ %4d", &dia, &mes, &anio);
        if (res != EOF) {
            if (res != 3){
                printf("ERROR: El formato debe ser dd/mm/yyyy\n");
                while ((res=getchar())!=EOF && res!='\n');
            } else {
                printf("Fecha: %d/ %d/ %d\n", dia, mes, anio);
            }   
        }
        
        
    } while (res != EOF);
    return 0;
}



//d. si se ingresa una letra en vez de un numero, scanf retorna un 0 y el programa se queda en un bucle.
//d. se arregla limpiando el buffer para que vuelva a scannear entrada.

//e. cree un archivo llamado archivo, correrlo usando ./ejer11 < archivo
