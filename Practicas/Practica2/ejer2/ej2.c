#include <stdio.h>

int main(){	
	printf("Enter a char: ");
	printf( (getchar() != EOF) ? "1 - true\n" : "\n0 - false\n");
	return 0;
}
