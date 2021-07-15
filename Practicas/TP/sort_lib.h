#ifndef SORT_LIB_H
#define SORT_LIB_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "str_vector_t.h"


void count_function();

void sort_file( /*@ in @*/  FILE *fpin, 
                /*@ in @*/  FILE *fpout,   
                /*@ in @*/ int   flag_r,
                /*@ in @*/ int   flag_s
                );

#endif