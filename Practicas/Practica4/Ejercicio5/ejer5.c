

// (*var).campo = var -> campo

#include <stdio.h>
#include <string.h>

struct person{
    int age;
    char name[10];
};

void read_person(struct person *var){
    var -> age = 19;
    strcpy(var->name, "Laura");    
}

int main(int argc, char const *argv[]) {
    struct person person1;  
    
    read_person(&person1);

    printf("age = %d, name = %s\n", person1.age, person1.name);

    return 0;
}
