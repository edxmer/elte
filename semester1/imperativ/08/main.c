#include <stdio.h>
#include "my_utils.h"

int main() {
    int a = 5;
    int b = 91;
    int *p;

    printf("I.: %d %d\n", a, b);

    swap(&a, &b);

    printf("II.: %d %d\n", a, b);

    p = bigger_pointer(&a, &b);
        
    printf("III.: %p %d\n", p, *p);

    printf("IV.\n");
    p1(5);
}