#include <stdio.h>
#include <string.h>
#include "asciiart.h"

#define BUFF_SIZE 2048

int main(int argc, char *argv[]) {
    

    if (argc < 2) {
        printf("Nincs elég argumentum!\n");
        return 5;
    }


    AsciiLetters letters;
    char str[BUFF_SIZE];
    int i;
    char c;
    
    printf("ctrl+d (unix) vagy ctrl+z+enter (windows) a kilépéshez\n");
    
    letters = read_letters(argv[1]);
    

    i = 0; 
    while ((c = getchar()) != EOF && i < BUFF_SIZE) {
        if (c == '\n') {
            str[i] = '\0';
            remove_newline(str); // hogy biztosan ne legyen a \r ott
            draw_str(str, letters);
            i = 0;
        }
        else {
            str[i] = c;
            ++i;
        }
    }


    free_letters(letters);

    return 0;
}
