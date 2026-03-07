#ifndef MATRIX_H
#define MATRIX_H


typedef struct Matrix Matrix;

struct Matrix {
    int* values;
    int m;
    int n;
};

Matrix construct_matrix (int m, int n);

void set_matrix (Matrix* matrix, int* values);

int* matrix_at (Matrix* matrix, int i, int j);

void print_matrix(Matrix* matrix);

Matrix matrix_mult (Matrix* a, Matrix* b);

void free_matrix(Matrix* matrix);

#endif
