// 2025-11-10 15:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
    char line[1024];
    char words[5][256];

    fgets(line, sizeof(line), stdin);

    sscanf(line, "%s %s %s %s %s", words[0], words[1], words[2], words[3], words[4]);

    

    for (int i = 4; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    printf("\n");



    return 0;
}
