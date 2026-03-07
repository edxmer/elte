// 2025-11-10 15:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Nem adtál meg elég argumentumot.\n");
        return 1;
    }
    
    int wc;
    int i;
    char line[1024];
    char **words;
    int n, pos;

    wc = atoi(argv[1]);
    
    words = malloc(sizeof(char*) * wc);    

    for (i = 0; i < wc; ++i) {
        words[i] = malloc(sizeof(char) * 256);
    }
    
    

    fgets(line, sizeof(line), stdin);
    
    i = 0;
    pos = 0;
    while ( i < wc && sscanf(line + pos, "%s%n", words[i], &n) == 1) {
        ++i;
        pos += n;
    }


    for (int i = wc-1; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    printf("\n");

    

    return 0;
}
