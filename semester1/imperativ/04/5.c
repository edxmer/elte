// 2025-10-11 12:39
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    

    char str[32];
    printf("Az oszlopneved: (csak A-Z karaktereket használj): ");
    fgets(str, sizeof(str), stdin);

    unsigned long long value = 0;
    int length = strlen(str) - 1;
    int AtoZ = 'Z' - 'A' + 1;
    for (int i = 0; i < length; i++) {
        if (str[i] < 'A' || str[i] > 'Z') {
            printf("Nem megfelelő szöveget adtál meg.\n");
            return 0;
        }
        value += (str[i] - 'A' + 1) * pow(AtoZ, length-i-1);
    }

    printf("%llu az értéke.\n", value);

    return 0;
}