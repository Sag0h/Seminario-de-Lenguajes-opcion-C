#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("El valor de EOF es: %d\n", EOF);
	return 0;
}



/*
int main(){
	char c;

	printf("Ingrese un char: "; 
	c = getchar();

	while(c != EOF){
		printf("Ingrese un char: ");
		c = getchar;
	}
	
	printf("%d\n", c);


	return 0;
}

*/ 
//No es correcto porque EOF es -1. no esta en los valores de char, y se queda en loop.