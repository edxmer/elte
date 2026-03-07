#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix construct_matrix (int m, int n) {
    
    Matrix matrix;

    matrix.values = (int*) calloc (m * n, sizeof(int));
    matrix.m = m;
    matrix.n = n;
    
    return matrix;

}


void set_matrix (Matrix* matrix, int* values) {
    int i, j;

    for (i = 0; i < matrix->m; ++i)
        for (j = 0; j < matrix->n; ++j) {
            *matrix_at(matrix, i, j) = values[i * matrix->n + j];
    }
}


int* matrix_at (Matrix* matrix, int i, int j) {
    return matrix->values + (i * matrix->n + j);
}

void print_matrix(Matrix* matrix) {
    int i, j;

    for (i = 0; i < matrix->m; ++i) {
        for (j = 0; j < matrix->n; ++j) {
            printf("%d\t", *matrix_at(matrix, i, j));
        }
        printf("\n");
    }
}


Matrix matrix_mult (Matrix* a, Matrix* b) {
    int i, j, k;

    if (a->n != b->m) {
        Matrix error_matrix = {NULL, 0, 0};
        return error_matrix;
    }
    
    Matrix axb = construct_matrix(a->m, b->n);

    for (i=0; i < a->m; ++i)
        for (j=0; j < b->n; ++j )
            for (k=0; k < a->n; k++)
                *matrix_at(&axb, i, j) += (*matrix_at(a, i, k)) * (*matrix_at(b, k, j));
    return axb;

}

void free_matrix(Matrix* matrix) {
    free(matrix->values);
    matrix->n = 0;
    matrix->m = 0;
}
