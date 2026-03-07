// 2025-10-06 15:01
#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    
    printf("a: %d, b: %d\n", a, b);
    
    int *p1, **p2, ***p3;
    p1 = &a;
    p2 = &p1;
    p3 = &p2;

    **p3 = &b;

    ***p3 = 9;

    printf("a: %d, b: %d\n", a, b);
    return 0;
}