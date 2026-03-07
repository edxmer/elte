#include "menu.h"
#include "matrix.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void printUserGuide() {
    printf("\tSPIRAL MATRIX PRO™\n");
    printf("0 - Print this user guide\n");
    printf("1 - Generate matrix\n");
    printf("2 - Save matrix\n");
    printf("3 - Load matrix\n");
    printf("4 - Print current matrix\n");
    printf("5 - Exit\n");
}

void rstrip(char *str) {
    int l;
    l = strlen(str) - 1;
    if (isspace(str[l])) str[l] = '\0';
}

int takeNumber(int *num) {
    char buff[256];
    printf("n: ");
    if (fgets(buff, sizeof(buff), stdin) && sscanf(buff, "%d", num) == 1)
        return 1;
    return 0;
}

int takeString(char *buff, int size) {
    printf("path: ");
    if (fgets(buff, size, stdin))
        rstrip(buff);
        return 1;
    return 0;
}

int takeDirection(Direction *d) {
    char buff[256];

    printf("Direction (up/down/left/right): ");

    if (fgets(buff, sizeof(buff), stdin)) {
        rstrip(buff);
        if (strcmp(buff, "up") == 0) {
            *d = Up;
        } else if (strcmp(buff, "down") == 0) {
            *d = Down;
        } else if (strcmp(buff, "left") == 0) {
            *d = Left;
        } else if (strcmp(buff, "right") == 0) {
            *d = Right;
        } else {
            return 0;
        }
        return 1;
    }
    return 0;
}

int takeRotation(Rotation *r) {
    char buff[256];

    printf("Rotation (cw/ccw): ");

    if (fgets(buff, sizeof(buff), stdin)) {
        rstrip(buff);
        if (strcmp(buff, "cw") == 0) {
            *r = CW;
        } else if (strcmp(buff, "ccw") == 0) {
            *r = CCW;
        } else {
            return 0;
        }
        return 1;
    }
    return 0;
}

int takeUserInput(Matrix *mx) {
    char buff[1024];
    int command, n;
    Direction d;
    Rotation r;
    Matrix mx2;

    printf("Run » ");
    
    if (!fgets(buff, sizeof(buff), stdin)) {
        printf("Error in function 'takeUserInput': did not manage to read in to buffer from stdin.\n");
        return 0;
    }

    if (sscanf(buff, "%d", &command) != 1) {
        printf("Wrong input! Try again.\n");
        return 1;
    }

    switch (command) {
        case 0:
            printUserGuide();
            break;
        case 1:
            if (takeNumber(&n) && takeDirection(&d) && takeRotation(&r)) {
                printf("Generating a spiral matrix...\n");
                freeMatrix(mx);
                initMatrix(mx, n);
                generateSpiralMatrix(mx, d, r);
            }
            else {
                printf("Wrong input! Try again.\n");
            }
            break;
        case 2:
            if (takeString(buff, sizeof(buff)) && saveMatrix(mx, buff)) {
                printf("Succesfully saved matrix to %s!\n", buff);
            }
            else {
                printf("Failed to save matrix to %s!\n", buff);
            }
            break;
        case 3:
            if (takeString(buff, sizeof(buff)) && loadMatrix(&mx2, buff)) {
                freeMatrix(mx);
                *mx = mx2;
                printf("Succesfully loaded matrix from %s!\n", buff);
            }
            else {
                printf("Wrong input! Try again.\n");
            }
            break;
        case 4:
            printMatrix(mx);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Wrong input! Try again.\n");
    }
    
    return 1;
}
