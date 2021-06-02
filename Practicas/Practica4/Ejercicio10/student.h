#ifndef STUDENT_H
#define STUDENT_H

#include "date.h"

struct student{
    char name[10];
    char last_name[12];
    date_t birthdate;
};

typedef struct student *student_t;

void initialize_student(student_t *student, char *name, char *last, int d, int m, int y);

char *to_string(char *str, student_t student);

int student_cmp(student_t s1, student_t s2);
// devuelve 0 si los nombres no coinciden 
// devuelve 1 si los structs son iguales 
// devuelve -1 si solo coincide el nombre y apellido

void destroy_student(student_t *student);

#endif