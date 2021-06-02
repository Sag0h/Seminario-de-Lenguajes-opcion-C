#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_student(student_t *student, char *name, char *last, int d, int m, int y) {
    *student = malloc(sizeof(struct student));
    strcpy((*student)->name, name);
    strcpy((*student)->last_name, last);
    (*student)->birthdate.day = d;
    (*student)->birthdate.month = m;
    (*student)->birthdate.year = y;  
}

char *to_string(char *str, student_t student) {
    char aux[1024] = "Alumno= ";
    strcat(aux, student->name);
    strcat(aux, " ");
    strcat(aux, student->last_name);
    strcat(aux, " | Fecha de nacimiento= ");
    char date_aux[5];
    
    sprintf(date_aux, "%.2d", student->birthdate.day);
    strcat(aux, date_aux);
    strcat(aux, "/");
    sprintf(date_aux, "%.2d", student->birthdate.month);
    strcat(aux, date_aux);
    strcat(aux, "/");
    sprintf(date_aux, "%.4d", student->birthdate.year);
    strcat(aux, date_aux);

    strcpy(str, aux);
    return str;
}

int student_cmp(student_t s1, student_t s2) {

    int ok = 0;

    if((!strcmp(s1->name, s2->name))&&(!strcmp(s1->last_name, s2->last_name))){
        ok = -1;
        if((s1->birthdate.day == s2->birthdate.day)&&(s1->birthdate.month == s2->birthdate.month)&&(s1->birthdate.year == s2->birthdate.year)) {
            ok = 1;
        }
    };

    return ok; 
    
    // devuelve 0 si los nombres no son iguales 
    // devuelve 1 si los structs son iguales 
    // devuelve -1 si solo coincide el nombre y apellido

}

void destroy_student(student_t *student) {
    free(*student);
}