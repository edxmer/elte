// 2025-10-13 15:00
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp = fopen("player.txt", "w");

    char name[64];

    fgets(name, sizeof(name), stdin);

    // \n levétele
    name[strlen(name)-1] = '\0';

    fputs(name, fp);

    fclose(fp);

    return 0;
}
