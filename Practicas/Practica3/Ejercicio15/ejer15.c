#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char pw[] = "abracadabra";
    int ok = 0, i;
    for(i = 1; i < argc; i++){
        // !strcmp bc returns 0 if they match
        if((ok = !strcmp(argv[i],pw))) {
            puts("C is quirky, flawed, and an enormous success. - Dennis Ritchie");
            break;
        } 
    }
    if(!ok){
        // i-1 bc "i" starts as 1, on argument 0 is the name of program 
        printf("%d argumento/s",(i-1));
    }
    return 0;
}
