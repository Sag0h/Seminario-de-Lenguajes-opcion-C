#include "student.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
    student_t student;
    initialize_student(&student, "Miqueas", "Brambilla", 16, 03, 2000);
    char str[1024];
    puts(to_string(str, student));
    student_t s2;
    initialize_student(&s2, "Miq", "Brambilla", 16, 03, 2000);
    int aux;
    if((aux = student_cmp(student, s2))){
        if(aux == 1){
            puts("Son iguales.");
        }else{
            puts("Los nombres coinciden, la fecha de nacimiento no.");
        }
    }else{
        puts("No coinciden.");
    }
    
    destroy_student(&student);
    destroy_student(&s2);
    return 0;
}
