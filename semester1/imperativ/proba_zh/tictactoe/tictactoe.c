#include <stdio.h>

#define HEIGHT 6
#define WIDTH 7
int board[WIDTH][HEIGHT];

void init() {
    int i, j;

    for (i=0; i<WIDTH; ++i) for (j=0; j<HEIGHT; ++j) {
        board[i][j] = 0;
    }
}

void printTable() {
    int i, j;

    for (j=0; j<HEIGHT; ++j) {
        for (i=0; i<WIDTH; ++i) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

int submit(int player, char column) { // 0 if bad move, 1 if good move
    if (!(player == 1 || player == 2)) {
        fprintf(stderr, "Error in function 'submit': wrong input on player.\n");
        return 0;
    }
    if (!( 'A' <= column && column <= 'A' + WIDTH - 1 )) {
        fprintf(stderr, "Error in function 'submit': wrong input on column.\n");
        return 0;
    }
    
    int col_int = (int)(column - 'A');

    int i = -1;

    while (i < HEIGHT - 1 && board[col_int][i+1] == 0) {
        ++i;
    }

    if (i == -1) {
        fprintf(stderr, "Error in function 'submit': column is full.\n");
        return 0;
    }


    board[col_int][i] = player;
    return 1;
}

int evaluate() { // 0 - nem nyert senki, 1 - 1. nyert, 2 - 2. nyert
    int i, j;
    for (i=0; i<WIDTH; ++i) for (j=0; j<HEIGHT; ++j) {
        if (i<WIDTH-2
            && board[i][j] != 0
            && board[i][j] == board[i+1][j]
            && board[i][j] == board[i+2][j]
        ) {
            return board[i][j];
        }
        if (j<HEIGHT-2
            && board[i][j] != 0
            && board[i][j] == board[i][j+1]
            && board[i][j] == board[i][j+2]
        ) {
            return board[i][j];
        }
    }
    return 0;
}

int game(char *moves) { // 0 - draw, 1 - 1st won, 2 - 2nd won
    int player = 1;
    int i, k, x;
    for (i=0; moves[i] != '\0'; ++i) {

        if ((x = submit(player, moves[i]))) { // good move
            player = 3 - player;
        }

        if ((k = evaluate())) {
            return k;
        }
    }
    return 0;
}

void printResult(int result) {
    switch (result) {
        case 0:
            printf("Draw.\n");
            break;
        case 1:
            printf("First player wins.\n");
            break;
        case 2:
            printf("Second player wins.\n");
            break;
        default:
            fprintf(stderr, "Error in switch (result): wrong result given!\n");
    }
}

int main(void) {
    int result;
    char game1[] = "ABDCAGEEE";
    char game2[] = "ABDCAEEEEEEFFFAC";
    char game3[] = "ABDCAEEEEEEFFG";
    char game4[] = "AAAAAAABBBBBBBCCCCCCCDDDDDDDEEEEEEEFFFFFFFGGGGGG";

    init();
    result = game(game4);
    printTable();
    printResult(result);
}
