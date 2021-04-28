#include <stdio.h>

int main(int argc, char const *argv[]){
    float a, b;
    int res;
    char c;
    printf("Ingresar una operacion aritmetica simple ( a + b or a / b or a * b or a - b): ");
    res = scanf("%f %c %f", &a, &c, &b);
    while ((res != EOF)&&(res == 3)) {
        switch (c)
        {
        case '+':
            printf("\nresultado: %f\n", a+b);
            break;
        case '-':
            printf("\nresultado: %f\n", a-b);
            break;
        case '*':
            printf("\nresultado: %f\n", a*b);
            break;
        case '/':
            printf("\nresultado: %f\n", a/b);
            break;  
        default:
            res = -1;
            printf("Se ingreso un operando invalido.\n");
            break;
        }
        if(res == 3){
            printf("\nIngresar una operacion aritmetica simple ( a + b or a / b or a * b or a - b): ");
            res = scanf("%f %c %f", &a, &c, &b);  
        }         
    }   
    return 0;
}
