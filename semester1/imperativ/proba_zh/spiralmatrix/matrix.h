
#ifndef MATRIX_H
#define MATRIX_H

typedef enum {
    Up, Down, Left, Right
} Direction;

typedef enum {
    CW, CCW
} Rotation;

typedef struct {
    int n;
    int *data;
} Matrix;

void initMatrix(Matrix *mx, int n);

int getMatrix(Matrix *mx, int i, int j);

void setMatrix(Matrix *mx, int i, int j, int value);

void printMatrix(Matrix *mx);

void generateSpiralMatrix(Matrix *mx, Direction d, Rotation r);

int saveMatrix(Matrix *mx, char *path);

int loadMatrix(Matrix *mx, char *path);

void freeMatrix(Matrix *mx);

#endif
