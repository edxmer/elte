/*
Írd ki, hogy hány bájton ábrázol a géped egy int, unsigned, long, short, float, double, long double értéket
*/

#include <stdio.h>

int main() {

    printf("int: %lu\n", sizeof(int));
    printf("usigned: %lu\n", sizeof(unsigned));
    printf("long: %lu\n", sizeof(long));
    printf("short: %lu\n", sizeof(short));
    printf("float: %lu\n", sizeof(float));
    printf("double: %lu\n", sizeof(double));
    printf("long double: %lu\n", sizeof(long double));
}