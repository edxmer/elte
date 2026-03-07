// 2025-10-26 18:04
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char from[] = "abcdefghijklmnopqrstuvwxyz";
char *morse[] = {
        ".-",    // a
        "-...",  // b
        "-.-.",  // c
        "-..",   // d
        ".",     // e
        "..-.",  // f
        "--.",   // g
        "....",  // h
        "..",    // i
        ".---",  // j
        "-.-",   // k
        ".-..",  // l
        "--",    // m
        "-.",    // n
        "---",   // o
        ".--.",  // p
        "--.-",  // q
        ".-.",   // r
        "...",   // s
        "-",     // t
        "..-",   // u
        "...-",  // v
        ".--",   // w
        "-..-",  // x
        "-.--",  // y
        "--.."   // z
    };

char *to_morse(char c) {
    c = tolower(c);

    for ( int i = 0; i < sizeof(from)-1; ++i ) {
        if (from[i] == c)
            return morse[i];
    }

    static char single[] = " ";
    single[0] = c;
    return single;
}


int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        printf("Nem jó az argumentum szám.\n");
        return 1;
    }

    // Deklaráció
    char buff[2048];
    FILE *fp_original;
    FILE *fp_morse;
    int i;


    // Beolvasás

    fp_original = fopen(argv[1], "r");
    fp_morse = fopen(argv[2], "w+");

    if (fp_original == NULL || fp_morse == NULL) {
        printf("Nem sikerült sikeresen beolvasni az egyik fájlt.\n");
        return 2;
    }

    while (fgets(buff, sizeof(buff), fp_original)) {
        for (i = 0; i < strlen(buff); ++i) {
            fputs(to_morse(buff[i]), fp_morse);
            if (i < strlen(buff) - 1)
                fputs(" ", fp_morse);
        }
    }

    fclose(fp_original);
    fclose(fp_morse);
    return 0;
}

/*


            O
           /|\
           /\

*/