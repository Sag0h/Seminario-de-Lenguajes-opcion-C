#include <stdio.h>

struct date{
    int year;
    int month;
    int day;
};

typedef struct date date_t;

void initialize_date(date_t *d){
    d->day = 1;
    d->month = 1;
    d->year = 1970;
}

int main(int argc, char const *argv[]){
    date_t d1;
    initialize_date(&d1);
    date_t d2 = d1;
    printf("d1 = %.2d/%.2d/%4d\nd2 = %.2d/%.2d/%4d\n", d1.day, d1.month, d1.year, d2.day, d2.month, d2.year);
    return 0;
}

// si es posible igualar, no se si es correcto, supongo que si, siempre y cuando no usen punteros.
