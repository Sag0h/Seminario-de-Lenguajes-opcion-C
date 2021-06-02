#include <stdio.h>

int var_1 = 3;

void alter_var_1_A() {
    int var_1;
    var_1++;
}

void alter_var_1_B() {
    extern int var_1;
    var_1++;
}

void alter_var_1_C() {
    var_1++;
}

int main() {
    printf("El valor inicial de var_1 es: %d\n", var_1);
    alter_var_1_A();
    printf("El valor luego de alter_var_1_A es: %d\n", var_1);
    alter_var_1_B();
    printf("El valor luego de alter_var_1_B es: %d\n", var_1);
    alter_var_1_C();
    printf("El valor luego de alter_var_1_C es: %d\n", var_1);
    return 0;
}

//conclusiones,
// si existe una variable con el mismo nombre \ 
// se trabaja con la variable local
//
// si se especifica que la var es extern o no existe ninguna variable local \
// con ese nombre, se toma la global, o la externa. 