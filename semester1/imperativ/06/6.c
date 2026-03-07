// 2025-10-26 12:57
#include <stdio.h>

int main(int argc, char* argv[]) {
    
    // Argumentum ellenőrzés

    if (argc < 2) {
        printf("Nem elég argumentum!\n");
        return 1;
    }
    else if (argc > 2) {
        printf("Túl sok argumentum!\n");
        return 2;
    }


    // Deklaráció
    FILE *fp;
    int sum;
    int num;
    char buff[256];


    // Beolvasás
    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Hiba a fájl megnyitásában.\n");
        return 3;
    }


    // Feoldolgozás
    sum = 0;
    while (fgets(buff, sizeof(buff), fp)) {
        if (sscanf(buff, "%d", &num) == 1)
            sum += num;
    }

    // Kiírás
    printf("%d az összeg.\n", sum);

    fclose(fp);

    return 0;
}