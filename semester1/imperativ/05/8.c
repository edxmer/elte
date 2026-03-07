// 2025-10-12 21:23
#include <stdio.h>

double sum(double *first, double *afterlast) {
    double result = 0;
    for (double *i = first; i < afterlast; i += 1) {
        result += *i;
    }
    result /= (double)(afterlast-first);
    return result;
}

int main() {
    double numbers[] = {1,2,3,4,8,7,9,9,8,3,2,1,1,8,9,9,9,9,9};

    printf("%f az átlag\n", sum(
        numbers,
        numbers + sizeof(numbers)/sizeof(*numbers)
    ));

    return 0;
}