#include <stdio.h>

//Función para mostrar estado de la lista
void mostrarLista(int *lista, int cant){
	int i;
	for (i=0; i< cant
    ; i++){
		printf("%d ",*(lista+i));
	}
	printf("\n");
}

int main(int argc, char const *argv[]){
	int arreglo[ ]={ 5, 2, 4, 1, 3};
    const int cant = 5;
	int i,clave,j;
   //Recorrer el arreglo
	for (i = 1; i < cant; i++){	   
		clave = *(arreglo+i);
		j = i-1;
		//Comparar el valor selecionado con todos los valores anteriores
		while (j >= 0 && *(arreglo+j) > clave){
			//Insertar el valor donde corresponda
			*(arreglo+j+1) = *(arreglo+j);
			j = j-1;
		}
		*(arreglo+j+1) = clave;
	}    
	mostrarLista(arreglo,cant);  
	return 0;
}