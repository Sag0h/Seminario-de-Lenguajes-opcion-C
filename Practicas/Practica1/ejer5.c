#include <limits.h> // Para usar UINT_MAX
#include <stdio.h>

char uno(){ 
    char c;
    c = 'A' + 2;
    return (c);
}  //retorna 12

int dos(){
    int a = 10;
    return ((a++ == 10)?a:--a);
}  // retorna  11

float tres(){
    float x = (int) 3.7 + 4.5;
    return x;
}  //retorna 8 creo

int cuatro(){
    float x=3.6;
    return (int)x;
}  //retorna 3

int cinco(){
    int a = 17, b;
    b = ++a % 3;
    return (b > 1);
}  //retorna 0 (false)

int seis(){
    int a = 3;
    a <<= 3; //desplaza los bits de a, 3 posiciones 
    // a = 3 -> 0000 0011 
    // a << = 3 -> 0001 1000
    // a = 24 (0001 1000)
    return a;
}  //retorna 24 

int siete (){
// Ver:
// https://www.gnu.org/software/libc/manual/html_node/Range-of-Type.html

    unsigned a = 8, b; //a = (0 1000)
    b = ~a; //b = (1 0111) todos los bit en 1 menos el de la posicion 2 ^3
    return (b == (UINT_MAX - 8)); //retorna 1, b -> es el complemento a1 de 8
    //  UINT_MAX = 1111 1111
    //  UINT_MAX - 8 -> 1111 0111
}

int ocho(){
    int i = 320;  
    return (char) i; //char range [0..255] -> 320 > 255, 0001 0100 0000 se pierden datos y retorna 0100 0000 = 64
}

double nueve(){
    char c = 'A';
    return (double) c;  //retorna el valor de ascii de 'A'=65 en double (65.00)
}

int main(){
    printf("valor %.2f \n",nueve());
    printf(cinco() ? "es true\n" : "es false\n");
    return 0;
}