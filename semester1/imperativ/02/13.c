#include <stdio.h>

int main() {

    int v = 21;
    int *a = &v;
    *a = 12;
    printf("*a: %lu %d, ", sizeof(*a), *a);
    printf("a: %lu %d, ", sizeof(a), a);
    int b[5];
    printf("*b: %lu %d, ", sizeof(*b), *b);
    printf("b: %lu\n", sizeof(b));

}