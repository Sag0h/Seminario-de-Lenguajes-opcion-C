#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){

    if(argc >= 2){
        int lim_inf;
        int lim_sup; 
        
        int flag_p = 0;
        int flag_i = 0;
        for(int i = 1; i < argc-1; i++) {
            if(!strcmp(argv[i], "-p")){
                flag_p++;
            }else if(!strcmp(argv[i], "-i")){
                flag_i++;
            }else{
                lim_inf = atoi(argv[i]);
                lim_sup = atoi(argv[i+1]);
            }
        }     
       
        if(lim_inf <= lim_sup){
                            
            for( int i = lim_inf; i <= lim_sup; i++){
                if(flag_i){
                    if((i % 2) == 1){
                        printf("%d ",i);
                    }
                }else if(flag_p){
                    if(i % 2 == 0){
                        printf("%d ",i);
                    }
                }else{
                    printf("%d ", i);
                }
            }
            
            puts("");
        }

    }else{
        puts("Cantidad de argumentos invalida.");
    }
    return 0;
}
