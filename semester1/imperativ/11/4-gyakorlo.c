#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void) {
    
    Matrix a = construct_matrix(3, 4);
    Matrix b = construct_matrix(4, 3);

    int va[] = {
        1, 2,  3,  4,
        5, 6,  7,  8,
        9, 10, 11, 12
    };

    set_matrix(&a, va);

    int vb[] = {
       1,  2,  3,
       4,  5,  6,
       7,  8,  9,
       10, 11, 12
    };

    set_matrix(&b, vb);
    
    Matrix c = matrix_mult(&a, &b);
    print_matrix(&a);
    print_matrix(&b);
    print_matrix(&c);

    free_matrix(&a);
    free_matrix(&b);
    free_matrix(&c);

    return 0;
}
