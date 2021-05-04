#include <stdio.h>

// void *puntero -> un puntero génerico (sin tipo)

int x;
void f() {
  int a = 0;
  static int b = 0; //tiempo de vida de variable global, alcance local
  printf("a = %d, b = %d\n",a++,b++);
}

int main(int argc, char const *argv[]) {
  int nro = 24;
  void *cosa;
  cosa = &nro;

  printf("nro = %d\n",nro);
  printf("&nro = %p\n", &nro);
  
  printf("cosa = %p\n", cosa);
  printf("&cosa = %p\n", &cosa);

  printf("*((int *) cosa) = %d\n", *((int *) cosa));

  //Ejemplo tiempo de vida de static en funcion:
  f();
  f();
  f();
  
  // Arreglos

  // int arreglo[5];
  // int matriz[5][5];

  // arreglo == &arreglo[0];

  // las funciones NO reciben arreglos como argumentos
  // reciben un puntero (verificar con sizeof())
  // Ejemplos:
  // int funcion(int a[]);
  // int funcion(int a[5]);
  // int funcion(int *a);

  

  return 0;
}
