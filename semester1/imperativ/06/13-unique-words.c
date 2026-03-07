// 2025-10-26 16:05
#include <stdio.h>


int read_word ( char *str, char **word_start, int *word_length) {
    *word_start = str;
    *word_length = 0;

    // megszakító karakterek: '\0', '\n', ' ', ','            "asd"
 
    while (**word_start == ' '
        || **word_start == '\n'
        || **word_start == ','
        || **word_start == '\0' )
        if (**word_start == '\0')
            return 0;
        else
            ++*word_start;
    
    while (*(*word_start + *word_length) != ' '
        && *(*word_start + *word_length) != '\n'
        && *(*word_start + *word_length) != ','
        && *(*word_start + *word_length) != '\0' ) {
            ++*word_length;
        }
    
    return 1;

} // return 1, ha sikerült szót találni, 0 ha nem

int word_comp(char* first, char* second, int length) {
    int i;
    for (i = 0; i < length; ++i) {
        if (*(first+i) != *(second+i))
            return 0;
    }
    return 1;
} // 0 - nem egyenlőek; 1 - egyenlőek

int is_word_unique(char* word, int word_length, char *unique_words[], int unique_wordc) {

    int i;
    for (i = 0; i < unique_wordc; ++i) {
        if (word_comp(word, unique_words[i], word_length))
            return 0;
    }

    return 1;
}


int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Nem jó az argumentum szám.\n");
        return 1;
    }

    // Deklaráció
    FILE *fp;
    char buff[4096];
    long len;

    char *unique_words[2048];
    int unique_wordc;

    char *word_start;
    int word_length;

    // Beolvasás
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Nem sikerült a fájl beolvasása.\n");
        return 2;
    }


    fseek(fp, 0, SEEK_END); // kurzort a legvégére teszem
    len = ftell(fp); // a kurzor távolsága a kezdettől
    rewind(fp); // same as fseek(fp, 0, SEEK_SET); // kurzort a legelejére visszateszem


    fread(buff, 1, len, fp);
    buff[len] = '\0';
    // a bufferbe, 1 byteonként, len elemet olvasson be az fp-ből, a kurzor pozíciójától


    // Feldolgozás
    unique_wordc = 0;
    word_start = buff;
    word_length = 0;

    while (read_word(word_start + word_length, &word_start, &word_length)) {
        if (is_word_unique(word_start, word_length, unique_words, unique_wordc)) {
            unique_words[unique_wordc] = word_start;
            ++unique_wordc;
        }
    }

    // Kiírás
    printf("%d egyedi szó van.\n", unique_wordc);


    fclose(fp);
    return 0;
}