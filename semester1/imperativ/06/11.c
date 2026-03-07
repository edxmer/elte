// 2025-10-26 14:30
#include <stdio.h>
#include <string.h>

char change_v1(char c) {
    // 1. verzio

    if (c == 'a')
        return 'e';
    if (c == 'e')
        return 'i';
    if (c == 'i')
        return 'o';
    if (c == 'o')
        return 'u';
    if (c == 'u')
        return 'a';

    return c;
}

char change_v2(char c) {
    // 2. verzio

    switch (c) { // nem kellenek breakek, mert return van
        case 'a':
            return 'e';
        case 'e':
            return 'i';
        case 'i':
            return 'o';
        case 'o':
            return 'u';
        case 'u':
            return 'a';
        default:
            return c;
    }
}

char change_v3(char c) {
    // 3. verzio

    char from[] = "aeiou";
    char to[] = "eioua";

    int i;
    for (i = 0; i < sizeof(from)-1; ++i)
        if (c == from[i])
            return to[i];

    return c;

}

char change_v4(char c) {
    // 3. verzio

    char *change_map[] = { "aeiou", "eioua" };

    int i;
    for (i = 0; i < strlen( change_map[0] ); ++i)
        if (c == change_map[0][i])
            return change_map[1][i];

    return c;

}

int main() {
    
    char buff[256];

    fgets(buff, sizeof(buff), stdin);

    char *p = buff;
    while (*p != '\0') {
        *p = change_v4(*p);
        ++p;
    }


    printf("%.255s", buff);

    return 0;
}