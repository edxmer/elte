#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asciiart.h"

void remove_newline (char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[(len--) - 1] = '\0';
    // strip windows-style line ending
    // ezzel annyit szenvedtem hogy rájöjjek hogy ez a hiba
    if (len > 0 && str[len - 1] == '\r') str[len - 1] = '\0';
}

AsciiLetters read_letters(char *input) {

    AsciiLetters asciiletters;
    FILE *fp;
    char buff[1024];
    int i, j, len;
    AsciiLetter *letter;


    fp = fopen(input, "r");

    if (fp == NULL) {
        printf("A megadott fájl nem megnyitható.\n");
        exit(6);
    }


    if (fgets(buff, sizeof(buff), fp)) {
        
        if (sscanf(buff, "%d", &asciiletters.thickness) != 1) {
            printf("Nem sikerült konvertálni a betűk vastagságát számmá! (%s:1)\n", input);
            exit(2);
        }        
    }
    else {
        printf("Nem sikerült beolvasni a betűk vastagságát tartalmazó sort! (%s:1)\n", input);
        exit(1);
    }

    asciiletters.letters = (AsciiLetter*) malloc( sizeof(AsciiLetter) * 26);
    if (!asciiletters.letters) {
        printf("Nem sikerült lefoglalni a memóriaterületet.\n");
        exit(7);
    }

    for (i = 0; i < 26; ++i) {
    
        letter = asciiletters.letters + i;

        letter->art = (char**) malloc( sizeof(char*) * asciiletters.thickness);
        if (!letter->art) {
            printf("Nem sikerült lefoglalni a memóriaterületet.\n");
            exit(8);
        }

        for (j = 0; j < asciiletters.thickness; ++j) {
            if (!fgets(buff, sizeof(buff), fp)) {
                printf("Nem sikerült beolvasni a fájl %d. sorát!\n", i*asciiletters.thickness + j + 2);
                exit(3);
            }
            
            remove_newline(buff);

            len = strlen(buff);
            if (j == 0)
                letter->wideness = len;

            if (len != letter->wideness) {
                printf("Nem egyenlők a '%c' betű ASCII ART sorainak szélességei! (%s:%d)\n", 'a' + i, input, i*asciiletters.thickness + j + 2);
                exit(10);
            }

            letter->art[j] = (char*) malloc( sizeof(char) * (letter->wideness + 1));
            if (!letter->art[j]) {
                printf("Nem sikerült lefoglalni a memóriaterületet.");
                exit(9);
            }

            strcpy(letter->art[j], buff);
        }
    }
    
    fclose(fp);
    return asciiletters;
}

void draw_str(char *str, AsciiLetters a) {
    int i, j;
    char *part;


    for (i = 0; i < a.thickness; ++i) {
        for (j = 0; str[j] != '\0'; ++j) { 

            if (!('a' <= str[j] && str[j] <= 'z')) {
                printf("\n\nNem megfelelő a bemenet! Csak az angol abc kisbetűit használd!\n");
                exit(4);
            }

            part = a.letters[(int)(str[j] - 'a')].art[i];
            
            printf("%s ", part);
        }
        printf("\n");
    }

    

}



void free_letters(AsciiLetters a) {
    int i, j;

    for (i = 0; i < 26; ++i) {
        for (j = 0; j < a.thickness; ++j) {
            free(a.letters[i].art[j]);
        }
        free(a.letters[i].art);
    }
    free(a.letters);
}
