#include <stdio.h>

int main(int argc, char const *argv[]){
  int c;
  while ((c = getchar())!= EOF){
    if (c == ' '){
      putchar(c);
      while (c == ' ' && c != EOF){
        c = getchar();
      }
      if(c != EOF){
        putchar(c);
      }
    }else{ 
    putchar(c);
    } 
  }
  putchar('\n');
  return 0;
}
