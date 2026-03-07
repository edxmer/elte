#include <stdio.h>

int main() {

    for (double f = -20; f <= 200; f += 10 ) {
        printf("%.2fF° = %.2fC°\n", f, (f-32) / 1.8);
    }

}