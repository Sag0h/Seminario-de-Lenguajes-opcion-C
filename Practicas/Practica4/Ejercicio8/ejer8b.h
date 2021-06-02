#ifndef EJER8B_H
#define EJER8B_H

struct date{
    int y;
    int m;
    int d;
};

typedef struct date date_t;

struct alumno{
    char *name; 
    char *last_name; 
    date_t birthday;  
    int file;
    char *doc_type;
    long doc_num;
};

typedef struct alumno alumno_t;

#endif