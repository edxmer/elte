// 2025-10-26 14:52
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    // Argumentumszám ellenőrzés
    if (argc != 3) {
        printf("Nem jó az argumentumszám! 2 argumentumot adjál meg.\n");
        return 1;
    }

    // Deklaráció
    FILE *fp;
    int n;
    int i;
    char line[1024];

    // Beolvasás
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("A fájl beolvasása sikertelen.\n");
        return 2;
    }

    n = atoi(argv[2]);



    i = 0;
    while ( i < n && fgets(line, sizeof(line), fp) )
        ++i;

    if (i == n)
        printf("%d. sor:\n%.1024s\n", i, line);
    else
        printf("A megadott fájlban nincs elég sor.");



    fclose(fp);
    return 0;
}