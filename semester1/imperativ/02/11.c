#include <stdio.h>
#include <math.h>

int dividers_sum (int n);


int main() {

    int a, b;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    int dsa = dividers_sum(a);
    int dsb = dividers_sum(b);

    if (dsa == b && dsb == a) {
        printf("A két szám barátságos.\n");
    }
    else {
        printf("A két szám nem barátságos.\n");
    }

}

int dividers_sum (int n) {

    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum;
}