#include <stdio.h>

int main(int argc, char const *argv[]){
  int ln = 0;
  int count = 0;
  int c;
  while((c = getchar()) != EOF){
    count++;
    if(c == '\n'){
      ln++;
    }
  }
  printf("Number of characters found: %d\nNumber of lines found: %d\n", count, ln);
  return 0;
}
