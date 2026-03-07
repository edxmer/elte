#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VERSION 2
#define SHOW_MINES_BY_DEFAULT 0



void drawTable(int [10][10], int [10][10], int [10][10]);
void initTable(int [10][10], int);
void countNeighbourMines(int [10][10]);
void recursiveZeros(int [10][10], int [10][10],int*, int, int, int, int);

int save(int[10][10], int[10][10], char*);
int load(char*, int[10][10], int[10][10], int*, int*);

int main() {
    srand(time(NULL));

    // deklaráció
    int table[10][10];
    int showntable[10][10];
    int revealtable[10][10];
    int marktable[10][10];
    int i, j;
    int aknak;
    char line[256];
    char buff1[128], buff2[128];
    int isPlaying;
    int guessed;
    int jo;


start_over:
    for (i = 0; i<10;i++)
        for (j = 0; j < 10; j++)
            showntable[i][j] = SHOW_MINES_BY_DEFAULT;
    for (i = 0; i<10;i++)
        for (j = 0; j < 10; j++)
            revealtable[i][j] = 1;
    for (i = 0; i<10;i++)
        for (j = 0; j < 10; j++)
            table[i][j] = 0;
    for (i = 0; i<10;i++)
        for (j = 0; j < 10; j++)
            marktable[i][j] = 0;


    printf("»»» Aknakereső V%d «««\n\n", VERSION);
    
    do {
        printf("Aknák száma (3 és 30 között): ");
        fgets(line, sizeof(line), stdin);
        jo = sscanf(line, "%d", &aknak);

        jo = jo && (3 <= aknak && aknak <= 30);

        if (!jo)
            printf("Helytelen bemenet! Próbáld újra.\n\n");
    } while (!jo);

    // inicializáció
    initTable(table, aknak);
    countNeighbourMines(table);
    
    drawTable(table, showntable, marktable);

    guessed = 0;
    isPlaying = 1;
    while (isPlaying) {
        
        // printf("DEBUG: guessed: %d, aknak: %d\n", guessed, aknak);
        printf("\nAdj meg egy koordinátát vagy parancsot: ");
        fgets(line, sizeof(line), stdin);
        int sor = toupper(line[0]) - 'A';
        int oszlop = line[1] - '0';

        if (sscanf(line, "%s %s", buff1, buff2) == 2) {
            if (strcmp(buff1, "save") == 0) {
                if ( save(table, showntable, buff2) ) {
                    printf("\nSikeresen mentve %s helyre.\n", buff2);
                }
                else {
                    printf("\nSikertelen mentés.\n");
                }
            } else if (strcmp(buff1, "load") == 0) {
                if ( load(buff2, table, showntable, &aknak, &guessed) ) {
                    drawTable(table, showntable, marktable);
                    printf("\nSikeresen betöltve %s helyről.\n", buff2);

                }
                else
                    printf("\nSikertelen betöltés.\n");

            } else if (strcmp(buff1, "mark") || strcmp(buff1, "MARK")) {
                i = toupper(buff2[0]) - 'A';
                j = buff2[1] - '0';
                if (0 <= i && i <= 9 && 0 <= j && j <= 9) {
                    if (marktable[i][j] == 0)
                        marktable[i][j] = 1;
                    else
                        marktable[i][j] = 0;
                    
                    drawTable(table, showntable, marktable);
                    printf("\nJelölés sikeresen megváltoztatlva %c%c helyen.\n", toupper(buff2[0]), buff2[1]);
                }
                else
                    printf("\nJelölés megváltoztatása sikertelen.\n");
            }

        }
        else if (0 <= sor && sor <= 9 && 0 <= oszlop && oszlop <= 9) {

            if (table[sor][oszlop] == -1) {
                // Aknára lépett

                printf("\nVesztettél!\n");
                drawTable(table, revealtable, marktable);
                isPlaying = 0;
            }
            else {
                // Jó helyre lépett
                if (!showntable[sor][oszlop]) {
                    guessed++;
                    showntable[sor][oszlop] = 1;
                    recursiveZeros(table, showntable, &guessed, 1, 0, sor, oszlop);
                }
                printf("\n");
                drawTable(table, showntable, marktable);
            }
            printf("\n");
        }
        else {
            printf("\nHelytelen bemenet! A helyes bemenetre példa: 'A3'\n\n");
        }

        if (guessed == 100-aknak) {
            // Nyertél
            printf("\nA megoldás:\n");
            drawTable(table, revealtable, marktable);
            printf("\n -- NYERTÉL! -- \n");

            printf("Újra akarod kezdeni? (igen/nem)\n\t");

            fgets(line, sizeof(line), stdin);
            if (sscanf(line, "%s", buff1) == 1) {
                if (strcmp(buff1, "igen\n"))
                    goto start_over;
            }
            isPlaying = 0;
        }
    }


}

void drawTable( int table[10][10], int showntable[10][10], int marktable[10][10] ) {
    int i, j;

    printf(" ");
    for (i = 0; i < 10; i++)
        printf(" %d", i);
    printf("\n");
    
    for (i = 0; i < 10; i++) {
        printf("%c", 'A' + i);

        for (j = 0; j < 10; j++) {
            if (marktable[i][j] == 1)
                printf(" ?");
            else if (showntable[i][j] == 1){
                if (table[i][j] == -1)
                    printf(" x");
                else    
                    printf(" %d", table[i][j]);
            }
            else
                printf(" -");
        }
        printf("\n");
    }
}

void initTable(int table[10][10], int n) {
    int i, j;
    while (n > 0) {
        i = rand() % 10;
        j = rand() % 10;
        if (table[i][j] != -1) {
            table[i][j] = -1;
            n--;
        }
    }
}

void countNeighbourMines(int table[10][10]) {
    int i, j, n;
    
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) {
            if (table[i][j] != -1) {
                n = 0;
                // mellette lévők
                if (i > 0)
                    if (table[i-1][j] == -1)
                        n++;
                if (i < 9)
                    if (table[i+1][j] == -1)
                        n++;
                if (j > 0)
                    if (table[i][j-1] == -1)
                        n++;
                if (j < 9)
                    if (table[i][j+1] == -1)
                        n++;
                // sarkok
                if (i > 0 && j > 0)
                    if (table[i-1][j-1] == -1)
                        n++;
                if (i > 0 && j < 9)
                    if (table[i-1][j+1] == -1)
                        n++;
                if (i < 9 && j > 0)
                    if (table[i+1][j-1] == -1)
                        n++;
                if (i < 9 && j < 9)
                    if (table[i+1][j+1] == -1)
                        n++;
                
                table[i][j] = n;
            }
        }
}

int save(int table[10][10], int showntable[10][10], char *path) {
    FILE *fp = fopen(path, "w");
    if (fp == NULL) return 0;

    char data[201];

    // data stuff
    int i, j;

    for (i=0; i<10; i++) 
        for (j=0; j<10; j++) {
            data[i*10+j] = (char)table[i][j] + 'B';
            data[100 + i*10+j] = (char)showntable[i][j] + 'B';
        }
    data[200] = '\0';
    // printf("%s", data);

    int success = fputs(data, fp) >= 0;
    fclose(fp);

    return success >= 0 && success != EOF;
    
}

int load(char *path, int table[10][10], int showntable[10][10], int *aknak, int *guessed) {

    int i, j;
    FILE *fp = fopen(path, "r");
    if (fp == NULL) return 0;

    char data[201];

    if ( fscanf(fp, "%200s", data) <= 0 ) return 0;
    fclose(fp);

    *aknak = 0;
    *guessed = 0;
    // data feldolgozása
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++) {
            table[i][j] = (int)data[i*10+j] - 'B';
            showntable[i][j] = (int)data[100 + i*10+j] - 'B';

            if (table[i][j] == -1)
                (*aknak)++;

            if (showntable[i][j] == 1)
                (*guessed)++;
        }



    // printf("%s", data);
    
    

    return 1;
}

// recursiveZeros(table, showntable, &guessed, 1, 0, sor, oszlop);
void recursiveZeros(int table[10][10], int showntable[10][10],int *guessed, int isFirst, int isPreviousZero, int i, int j) {
    if (!isFirst && showntable[i][j] == 1) return;
    else if ( table[i][j] == 0 || isFirst ) {
        if (!isFirst ) {
            (*guessed)++;
            showntable[i][j] = 1;
        }

        if (i > 0)
            recursiveZeros(table, showntable, guessed, 0, 1, i-1, j);
        if (i < 9)
            recursiveZeros(table, showntable, guessed, 0, 1, i+1, j);
        if (j > 0)
            recursiveZeros(table, showntable, guessed, 0, 1, i, j-1);
        if (j < 9)
            recursiveZeros(table, showntable, guessed, 0, 1, i, j+1);
    }
    else if (isPreviousZero && table[i][j] != -1) {
        (*guessed)++;
        showntable[i][j] = 1;
    }
}