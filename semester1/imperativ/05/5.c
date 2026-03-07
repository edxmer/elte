// 2025-10-06 15:13
#include <stdio.h>

int main() {
    void *a;
    a = &a;

    printf("a: %p\n", a);

    return 0;
}