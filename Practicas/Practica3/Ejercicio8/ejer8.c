
/*

char *strcat(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);
char *strcpy(char *dest, const char *src);
size_t strlen(const char *s);
char *strstr(const char *haystack, const char *needle);

1. concatena y devuelve la cadena concatenada

2. compara string 1 con string 2, pasados por parametro. \
devuelve un numero mayor a 0 si s1 es mayor que s2, \
si son iguales devuelve 0 y si s1 es menor que s2 devuelve un numero negativo. 

3. copia el string del primer parametro en la direccion del segundo parametro\
retorna un puntero a la direccion del primer parametro.

4. devuelve el largo del string sin el \0.

5. busca la primera ocurrencia del substring pasado como segundo parametro \
en el string del primer parametro, si lo encuentra retorna un puntero a la \
direccion de memoria del primer char de la subcadena, sino retorna null.

*/