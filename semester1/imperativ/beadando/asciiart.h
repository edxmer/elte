
#ifndef ASCIIART_H
#define ASCIIART_H


struct AsciiLetter {
    int wideness;
    char **art;
};
typedef struct AsciiLetter AsciiLetter;


struct AsciiLetters {
    int thickness;
    AsciiLetter* letters;
};
typedef struct AsciiLetters AsciiLetters;


void remove_newline(char *str);

AsciiLetters read_letters(char* input);

void draw_str(char* str, AsciiLetters);

void free_letters(AsciiLetters);


#endif

