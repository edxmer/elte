// 2025-10-26 12:44
#include <stdio.h>
//#include <stdlib.h>

int main() {
    FILE *fp = fopen("even_numbers.txt", "w");
    int szamok[] = {1,2,3,4,5,6,7,8,9,4112,1,231,23,12,3,51};
    int i;
    char buff[256];



    for (i = 0; i < sizeof(szamok)/sizeof(*szamok); ++i) {
        if (szamok[i] % 2 == 0) {
            sprintf(buff, "%d", szamok[i]);
            fputs(buff, fp);
            fputs("\n", fp);
        }
    }

    fclose(fp);


    return 0;
}