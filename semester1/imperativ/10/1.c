#include <stdio.h>

#define max(a, b) ( (a > b) ? (a) : (b) )

#define show(x) printf(#x "\n")

#include "square.h"

int n = 4;

int main() {
    
    // Kötelező feladatok

    // 1.
    int x = 7, y = 9;

    printf("max: %d\n", max(x, y));
    
    show(6);
    show(213);
    show(Hello there);

    //printf("%d\n", square(x));
    printf("%d\n", square());
}
