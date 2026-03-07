
// GYAKORLÓ FELADATOK

// 2025-10-26 13:32
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("yo.txt", "w");

    fputs("YOOOOO hello there\nmy friendsssss\nTTATAATATATA", fp);

    int i;
    scanf("%d", &i);

    fclose(fp);
    return 0;
}