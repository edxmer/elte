#include <stdio.h>

int main() {
    long long a, b;
    printf("a: "); scanf("%lld", &a);
    printf("b: "); scanf("%lld", &a);

    /*
    
    (a + b) / 2 = a / 2 + b / 2

    */

    long long ahalf = a / 2;
    long long bhalf = b / 2;

    long long average = ahalf + bhalf;

    printf("average: %lld\n", average);
}