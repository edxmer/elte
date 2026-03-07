#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char name[30];
    int* age;

} Person;

Person deepcopy(Person *p) {

    Person new;
    strcpy(new.name, p->name);
    new.age = malloc(sizeof(int));
    *new.age = *p->age;
    return new;
}

int main(void) {

    int x = 23;

    Person p1 = {"Pista", &x};
    
    printf("%s, %d\n", p1.name, *p1.age);

    
    Person p2 = deepcopy(&p1); 

    *p1.age = 15;

    printf("%s, %d\n", p2.name, *p2.age);

    return 0;
}
