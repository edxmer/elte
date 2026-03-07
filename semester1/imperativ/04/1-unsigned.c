#include <stdio.h>

signed negate(int n) {
    return n*(-1);
}
unsigned unegate(int n) {
    return n*(-1);
}

int main() {
    unsigned ua = 1;
    signed sa = 1;

    unsigned ub = unegate(ua);
    signed sb = negate(sa);

    printf("%u\n%d\n", ub, sb);
}