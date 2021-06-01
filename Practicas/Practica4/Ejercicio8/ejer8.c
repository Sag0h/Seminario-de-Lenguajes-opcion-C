#include "ejer8.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    alumno_t a1;
    a1.file = 24203;
    a1.birthday.y = 2000;
    a1.birthday.m = 2;
    a1.birthday.d = 14;
    a1.doc_num = 43462729;
    strcpy(a1.doc_type, "DNI");
    strcpy(a1.name, "Richard");
    strcpy(a1.last_name, "Ford");

    alumno_t a2 = a1;

    printf("A1= %s %s | doc = %s %ld | file num = %d | birthday = %.2d %.2d %.4d\n", a1.name, a1.last_name, a1.doc_type, a1.doc_num, a1.file, a1.birthday.d, a1.birthday.m, a1.birthday.y);
 
    printf("A2= %s %s | doc = %s %ld | file num = %d | birthday = %.2d %.2d %.4d\n", a2.name, a2.last_name, a2.doc_type, a2.doc_num, a2.file, a2.birthday.d, a2.birthday.m, a2.birthday.y);

    strcpy(a1.name, "Harold");

    printf("A1= %s %s | doc = %s %ld | file num = %d | birthday = %.2d %.2d %.4d\n", a1.name, a1.last_name, a1.doc_type, a1.doc_num, a1.file, a1.birthday.d, a1.birthday.m, a1.birthday.y);
 
    printf("A2= %s %s | doc = %s %ld | file num = %d | birthday = %.2d %.2d %.4d\n", a2.name, a2.last_name, a2.doc_type, a2.doc_num, a2.file, a2.birthday.d, a2.birthday.m, a2.birthday.y);

    return 0;
}