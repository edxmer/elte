#include <stdio.h>
#include <stdlib.h>

#define FOR(v, n, m) for (int v = n; v < m; ++v)


int* transpose (int* matrix, int m, int n) {
    

    int* mx_t = (int*)malloc(m * n * sizeof(int));

    FOR(i, 0, m) {
        FOR(j, 0, n) {
            
            mx_t[ j*m + i ] = matrix[ i*n + j ];

        }
    }    
    
    return mx_t;

}

void print_matrix(int* mx, int m, int n) {
    FOR(i, 0, m) {
        FOR(j, 0, n) {
            printf("%d\t", mx[ i*n + j ]);
        }
        printf("\n");
    }
}


int main() {
    
    // 1
    FOR(i, 0, 10) {
        printf("%d\n", i);
    }

    int matrix[] = {
        1, 2,  3,  4,
        5, 6,  7,  8,
        9, 10, 11, 12
    };
    int m = 3;
    int n = 4;


    int* mx_t = transpose(matrix, m, n);
    
    print_matrix(matrix, m, n);

    printf("\n");

    print_matrix(mx_t, n, m);


    // 2
    



}
