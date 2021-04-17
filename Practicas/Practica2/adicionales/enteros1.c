#include <stdio.h>

int main(int argc, char **argv){
    short x = 245;
    short y = 500;
    short z = x * y;
    printf(" %hd * %hd = %hd\n", x, y ,z);
    return 0;
}