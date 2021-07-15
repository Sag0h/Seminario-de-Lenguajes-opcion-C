#ifndef ERROR_SORT_H
#define ERROR_SORT_H  1

#include <stdio.h>

typedef int error_t;

//typedef enum m_err {E_OK, E_READ_ERROR, E_FORMAT_ERROR, ....} error_t;

#define   E_OK            0
#define   E_READ_ERROR    1
#define   E_WRITE_ERROR   2
#define   E_FILE_ERROR    3
#define   E_ALLOC_ERROR   4
#define   E_NOTIMPL_ERROR 10

int output_error(FILE *fp, error_t e);

#endif /*** error-sort.h ***/
