// 2025-10-26 14:23
#include <stdio.h>

int toLowerCase(char *s) {

    for ( ; *s != '\0'; ++s)
        if ('a' <= *s && *s <= 'z')
            *s = *s - 'a' + 'A';

    return 1;
}

int main() {
    char buff[256];

    fgets(buff, sizeof(buff), stdin);

    toLowerCase(buff);

    
    printf("%s", buff);

    return 0;
}