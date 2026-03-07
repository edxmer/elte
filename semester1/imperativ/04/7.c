// 2025-10-11 14:41
#include <stdio.h>
#include <string.h>


void printPermutations(char *str, char *cur, int len, int i);

int main() {
    char str[64];

    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    str[len-1] = '\0';
    printPermutations(str, str, len-1, 0);

    return 0;
}



void printPermutations(char *str, char *cur, int len, int i) {
    if (len == i) {

        cur[i+1] = '\0';

        printf("%s\n", cur);
    }
    char str2[64];
    char cur2[64];

    for(int j = 0; j < len; j++){
        if (!(str[j] == '\n')) {
            strcpy(str2, str);
            strcpy(cur2, cur);
            
            cur2[i] = str[j];
            str2[j] = '\n';

            printPermutations(str2, cur2, len, i+1);
        }
    }
}