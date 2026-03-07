#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initMatrix (Matrix *mx, int n) {
    mx->n = n;
    mx->data = calloc(n * n, sizeof(int));

    if (mx->data == NULL) {
        // Did not manage to allocate memory
        fprintf(stderr, "Error in function 'initMatrix': did not manage to allocate memory\n");
        exit(1);
    }
    // Managed to allocate memory
}

int getMatrix (Matrix *mx, int i, int j) {
    return mx->data[ i * mx->n + j ];
}

void setMatrix(Matrix *mx, int i, int j, int value) {
    if (i < 0 || mx->n <= i || j < 0 || mx->n <= j) {
        // Wrong input given
        fprintf(stderr, "Error in function 'setMatrix': wrong input given\n");
        exit(2);
    }
    mx->data[ i * mx->n + j ] = value;
}

void printMatrix(Matrix *mx) {
    int i, j;
    
    for (i=0; i<mx->n; ++i) {
        for (j=0; j<mx->n; ++j) {
            printf("%d\t", getMatrix(mx, i, j));
        }
        printf("\n");
    }

}


    /*
       CW 2x2 Matrix
        0 1
       -1 0
       (i, j) = (j_old, -i_old)
        
       CCW 2x2 Matrix
       0  -1
       1   0
       (i, j) = (-j_old, i_old)

    */


void turnCW(int *i, int *j) {
    int i_old;
    
    i_old = *i;
    
    *i = *j;
    *j = -i_old;
}

void turnCCW(int *i, int *j) {
    int i_old;

    i_old = *i;
    
    *i = -(*j);
    *j = i_old;
}

void turn(int *i, int *j, Rotation r) {
    if (r == CW)
        turnCW(i, j);
    else
        turnCCW(i, j);
}

void generateSpiralMatrix(Matrix *mx, Direction d, Rotation r) {
    int i, j, k, l, m, is_even_turn, i_offset, j_offset;

    i = mx->n/2;
    j = mx->n/2;


    if (mx->n % 2 == 0) { // Fixing the center of even matrices
        // Good diretions: Up+CCW, Left+CW
        if (d==Up && r==CW) {
            --j;
        } else if (d==Down && r==CW) {
            --i;
        } else if (d==Down && r==CCW) {
            --i;
            --j;
        } else if (d==Left && r==CCW) {
            --i;
        } else if (d==Right && r==CW) {
            --i;
            --j;
        } else if (d==Right && r==CCW) {
            --j;
        }
    }

    
    switch (d) {
        case Up:
            i_offset = -1;
            j_offset = 0;
            break;
        case Down:
            i_offset = 1;
            j_offset = 0;
            break;
        case Left:
            i_offset = 0;
            j_offset = -1;
            break;
        case Right:
            i_offset = 0;
            j_offset = 1;
            break;
        default:
            fprintf(stderr, "Error in function 'generateSpiralMatrix': wrong input on switch statement");
            exit(3);
    }

    
    is_even_turn = 1;
    l = 1;
    m = 2;
    for (k=1; k <= mx->n * mx->n; ++k) {
        setMatrix(mx, i, j, k);
        if (k == m) {
            turn(&i_offset, &j_offset, r);
            is_even_turn = !is_even_turn;
            if (is_even_turn)
                ++l;
            m += l;
        }
        i += i_offset;
        j += j_offset;
    }
}


int saveMatrix(Matrix *mx, char *path) {
    FILE *f;
    int i, j;
    
    f = fopen(path, "w");

    if (f == NULL) {
        fprintf(stderr, "Error in function 'saveMatrix': did not manage to open file.\n");
        return 0;
    }

    fprintf(f, "%d\n", mx->n);

    for (i=0; i<mx->n; ++i) {
        for (j=0; j<mx->n; ++j) {
            fprintf(f, "%d\t", getMatrix(mx, i, j));
        }
        fprintf(f, "\n");
    }

    fclose(f);

    return 1;
}

int loadMatrix(Matrix *mx, char *path) {
    FILE *f;
    char buff[4096];
    int i, j, n, x;
    char *start, *end;
    
    f = fopen(path, "r");

    if (f == NULL) {
        fprintf(stderr, "Error in function 'loadMatrix': did not manage to open file.\n");
        return 0;
    }

    if (!(fgets(buff, sizeof(buff), f) && sscanf(buff, "%d", &n) == 1)) {
        fprintf(stderr, "Error in function 'loadMatrix: did not manage to read n from the first line.\n'");
        fclose(f);
        return 0;
    }

    initMatrix(mx, n);

    for (i = 0; i < n; ++i) {
        if (!fgets(buff, sizeof(buff), f)) {
            fprintf(stderr, "Error in function 'loadMatrix': did not manage to load line %d.\n", i+2);
            fclose(f);
            return 0;
        }

        start = buff;
        end = buff;
        j = 0;

        while (isdigit(*start)) {
            end = start;
            while (isdigit(*end)) {
                ++end;
            }
            *end = '\0';

            if (!sscanf(start, "%d", &x)) {
                fprintf(stderr, "Error in function 'loadMatrix': did not manage to load value from line %d.\n", i+2);
                freeMatrix(mx);
                fclose(f);
                return 0;
            }

            setMatrix(mx, i, j, x);
            
            start = end + 1;
            ++j;
        }
    }
    
    fclose(f);
    return 1;
}

void freeMatrix(Matrix *mx) {
    mx->n = 0;
    free(mx->data);
}
