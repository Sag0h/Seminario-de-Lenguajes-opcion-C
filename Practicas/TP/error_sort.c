#include "error_sort.h"

int output_error(FILE *fp, error_t e)
{
  switch (e)
    {
  case E_OK:
    return fprintf(fp, "NO hay error (OK)");
  case -E_READ_ERROR:
    return fprintf(fp, "Error de lectura (READ)");
  case -E_ALLOC_ERROR:
    return fprintf(fp, "Error de memoria (ALLOC)");
  case -E_WRITE_ERROR:
    return fprintf(fp, "Error de escritura (WRITE)");
  case -E_NOTIMPL_ERROR:
    return fprintf(fp, "No implmenetado aun (NOTIMPL)");
  case -E_FILE_ERROR:
    return fprintf(fp, "Error de archivo (FILE)");    
  default:
    return fprintf(fp, "Error desconocido (UNKNOWN)");
    }
}

/*** EOF ***/
