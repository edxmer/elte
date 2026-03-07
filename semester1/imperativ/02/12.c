#include <stdio.h>

#define TRUE 1
#define FALSE 0

int is_prime(int n);

int main() {
    for (int i = 2; i <= 1000; i++) {

        if (is_prime(i)) {
            printf("%d is a prime number.\n", i);
        }
        else {
            printf("%d is not a prime number.\n", i);
        }
    }
}

int is_prime(int n) {
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0)
            return FALSE;
    }
    return TRUE;
}