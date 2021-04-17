#include <stdio.h>

#define mi_macro(t, a, b) {t _z##a##_##b = a; a = b; b = _z##a##_ ##b ;}

int main(int argc, char const *argv[])
{
    char t = 5;
    char a = 4;
    char b = 3;
    mi_macro(t,a,b);
    return 0;
}

//antes de compilar

//no tengo ni idea, se que concatena za_b y despues hace a = b 
//y luego hace que b sea iguala _zconcatenado con a_B
// pero no entiendo bien que hace

// despues de compilar