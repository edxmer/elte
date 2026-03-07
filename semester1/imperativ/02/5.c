#include <stdio.h>
#include <math.h>


int smallest_divider(int n) {
    for (int i = 2; i < n/2+1; i++) {
        if (n % i == 0)
            return i;
    }
    return n;
}

int main() {

    int n;
    scanf("%d", &n);

    printf("%d = ", n);
    while (1) {
        int divider = smallest_divider(n);

        if (divider == n) {
            printf("%d\n", divider);
            return 0;
        }

        printf("%d * ", divider);
        
        n /= divider;
    }

}