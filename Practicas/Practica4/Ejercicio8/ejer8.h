#ifndef EJER8_H
#define EJER8_H

struct date{
    int y;
    int m;
    int d;
};

typedef struct date date_t;

struct alumno{
    char name[10]; 
    char last_name[10]; 
    date_t birthday;  
    int file;
    char doc_type[4];
    long doc_num;
};

typedef struct alumno alumno_t;

#endif
