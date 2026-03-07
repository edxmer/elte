#include <stdio.h>
#include <stdlib.h>

int scalar_product (int *v1, int *v2, int n) {
    
    int result = 0;
    int i;
    for (i = 0; i < n; ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

int* matrix_mult (int *a, int *b, int m, int n, int p) {

    int *c = (int*) malloc(sizeof(int)*m*p);
    int i, j, k;
    int ind, inda, indb;
    
    for (i = 0; i < m; ++i)
        for (j = 0; j < p; ++j) {
            // printf("(%d, %d)\n", i, j);

            ind = i*n + j;
            c[ ind ] = 0;

            for (k = 0; k < n; ++k) {
                inda = i * n + k;
                indb = k * p + j;

                c[ind] += a[inda]*b[indb];
            }
        }
    
    return c;
}


int add(int a, int b) {
    return a+b;
}

int mult(int a, int b) {
    return a*b;
}

int vector_sum(int v[], int len, int (*f)(int, int)) {
    
    int i, out;
    
    if (len < 2) {
        return -1;
    }

    out = (*f)(v[0], v[1]);

    for (i=2; i<len; ++i) {
        out = (*f)(out, v[i]);
    }

    return out;
}


int main() {

    // Vektor skaláris szorzata
    
    int x[] = {1, 7, 1, 3, 9};
    int y[] = {5, 3, 0, 3, 1};

    int xy = scalar_product(x, y, sizeof(x)/sizeof(*x));
    
    printf("%d\n", xy);

    // Mátrixok:
    /*
    int A[] = { // m x n
        4, 1, 3,
        5, 6, 2
    };

    int B[] = { // n x p
        2, 1,
        1, 5,
        4, 2
    };


    int m = 2;
    int n = 3;
    int p = 2;
    }*/

    int A[] = {
        1, 0, 2,
        -1, 3, 5,
        6, 7, 0
    };
    
    int B[] = {
        -2, 1, 1,
        -1, 3, 3,
        -5, 0, 0
    };

    int m = 3;
    int n = 3;
    int p = 3;


    int *C; // m x p

    // Mátrix mult

    C = matrix_mult(A, B, m, n, p);
    
    int i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < p; ++j) {
            printf("%d ", C[i * p + j]);
        }
        printf("\n");
    }
    

    free(C);

    int l, k;

    l = vector_sum(x, sizeof(x)/sizeof(*x), mult);
    k = vector_sum(y, sizeof(y)/sizeof(*y), add);

    printf("%d, %d\n", l, k);

    return 0;
}
