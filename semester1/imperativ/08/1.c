#include <stdio.h>

int x = -1;

void y(int i) {
    printf("%d, i:%d\n", x, i);
    int z = 6;
    if (i == 1) {
        printf("Fő ág - %d\n", z);
    }
    else if (i == 2) {
        printf("Else if - %d\n", z);
        //int w = 3;
    }
    else {
        printf("Else - %d\n", z);
    }

    //printf("w: %d\n", w);


}

/*void two(int r, int r) {
    printf("%d\n", r);
}*/


void s(int plus) {
    static int n = 0;
    n += plus;
    printf("n: %d\n", n);
}


void swap(int *a, int *b) {
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int* bigger_pointer(int *a, int *b) {
    if (*a > *b) return a;
    else return b;
}

int  main () {
    printf("%d\n", x);
    x = 999;
    printf("%d\n", x);
    int x = 6;
    printf("%d\n", x);
    y(1);
    y(2);
    y(3);
    //printf("%d\n", z);

    printf("----\n");
    
    int q;
    {q = 1; {int q = -111; printf("%d\n", q); }}

    printf("%d\n", q);


    printf("---\n");

    //two(2, 7);

    s(1);
    s(2);
    s(3);
    s(4);
    s(10);


    printf("--- swap:\n");
    int f, s;
    f = 1;
    s = 69;
    printf("%d %d\n", f, s);
    swap(&f, &s);
    printf("%d %d\n", f, s);

    printf("--- bigger pointer:\n");
    int *p = bigger_pointer(&f, &s);
    printf("%p\t%d\n", p, *p);
    
}

