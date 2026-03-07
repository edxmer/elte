
#include <stdio.h>

void p1(int);
void p2(int);

void swap(int *a, int *b) {
    int temp;
    *a = *b;
    *b = temp;
}

int* bigger_pointer(int *a, int *b) {
    if (*a > *b) return a;
    else return b;
}

void p1(int n) {
    for (int i=0; i < n; ++i) {
        p2(i);
    }
}

void p2(int n) {
    printf("n: %d\n", n);
}