// 2025-10-26 13:11
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    // Argumentum ellenőrzés
    if (argc != 3) {
        printf("Nem jó az argumentumszám! 2 argumentumot adj meg.\n");
        return 1;
    }

    // Deklaráció
    FILE *fp;
    int type;

    // Beolvasás
    type = atoi(argv[1]);
    char pref[32];

    // Kiírás
    switch (type) {
        case 0:
            strcpy(pref, "INFO");
            break;
        case 1:
            strcpy(pref, "WARNING");
            break;
        case 2:
            strcpy(pref, "ERROR");
            break;
        default:
            strcpy(pref, "LOG");
    }

    // Kiírás
    printf("%s - %s\n", pref, argv[2]);



    return 0;
}