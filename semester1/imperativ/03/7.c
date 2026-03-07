// Szökőév? (nincs if)

#include <stdio.h>

int main() {
    unsigned int ev;
    printf("Év: "); scanf("%d", &ev);
    short szokoev = (ev % 400 == 0) || (ev % 4 == 0 && ev % 100 != 0);
    const char *out = szokoev ? "Ez ez év szökőév." : "Ez az év nem szökőév"; // !!!
    printf("%s\n", out);
}