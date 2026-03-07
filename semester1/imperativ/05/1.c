// 2025-10-06 14:47
#include <stdio.h>

int main() {
    int a = 2;
    int *b = &a;
    *b = 3;
    printf("%d\n", a);
    return 0;
}