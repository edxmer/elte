// 2025-10-12 21:53
#include <stdio.h>


int mystrlen(char *str) {
    int result = 0;

    while (*str != '\0') {
        str += 1;
        result += 1;
    }
    return result;
}

int mystrcmp(char *str1, char *str2) {

    while (*str1 == *str2) {
        if (*str1 == '\0')
            return 1;
        str1 += 1;
        str2 += 1;
    }
    return 0;
}


int main() {
    char str[] = "hello meoooooo";
    char str2[] = "hello meoooooo";
    char str3[] = "hello meoooeoeoe";

    printf("\"%s\" hossza: %d\n", str, mystrlen(str));

    if (mystrcmp(str, str2))
        printf("str==str2\n");

    if (mystrcmp(str, str3))
        printf("str==str3\n");

    return 0;
}