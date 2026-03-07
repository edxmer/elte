// 2025-10-11 12:00
#include <stdio.h>
#include <string.h>

int main() {
    char str[1024];

    printf("Stringed: ");
    fgets(str, sizeof(str), stdin);

    int length = strlen(str);
    printf("%d a hossza\n", length);

    return 0;
}