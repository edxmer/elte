// 2025-11-10 15:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    

    char *line;
    int line_len;

    int wc;
    char **words;

    char ch;
    int n, pos;
    int i;
    int isPrevSpace;
        
    // Read input till EOF chacacter ^+d
    line_len = 1;
    line = malloc(sizeof(char)*line_len);
    i = 0;
    while ( (ch = getchar()) != EOF){
        if (i == line_len - 1) {
            line_len *= 2;
            line = realloc(line, sizeof(char)*line_len);
        }
        line[i] = ch;
        ++i;
    }
    line[line_len] = '\0';

    // Input normalizálása
    for (i = 0; line[i] != '\0'; ++i)
        if ( isspace( (unsigned char)line[i] ) )
            line[i] = ' ';

    // Szavak száma
    isPrevSpace = 1;
    wc = 0;
    for (i = 0; line[i] != '\0'; ++i) {
        if (isPrevSpace) {
            if ( line[i] != ' ' ) {
                isPrevSpace = 0;
                wc++;
            }
        }
        if ( line[i] == ' ' )
            isPrevSpace = 1;
    }

    // Szavak eltárolása
    
    words = malloc( sizeof(char*) * wc );
    for (i = 0; i < wc; ++i) {
        words[i] = malloc(sizeof(char) * 64);
    }
    
    n = 0;
    pos = 0;
    i = 0;
    while ( sscanf(line + pos, "%s%n", words[i++], &n) == 1 )
        pos+=n;


    // Fordítva kiírás:
    printf("\n");
    for (i = wc - 1; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    printf("\n");



    // Memória felszabadítása
    for (i = 0; i < wc; ++i) {
        free(words[i]);
    }
    free(words);
    free(line);

    return 0;
}
