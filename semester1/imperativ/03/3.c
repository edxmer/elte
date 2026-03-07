#include<stdio.h>

int a (int n);
int b (int n);

int main() {
    int n;
    printf("Mondj egy számot: ");
    scanf("%d", &n);

    int iterations = a(n);

    printf("%d a-b iteráción ment keresztül.\n", iterations);

    return 0;
}

int a (int n) {
    n = n/2;
    int iterations;
    if (n > 0)
        iterations = b(n);
    else
        return 1;
    iterations++;
    return iterations;

}

int b (int n) {
    n = n-1;
    int iterations;
    if (n > 0)
        iterations = a(n);
    else
        return 1;
    iterations++;
    return iterations;
}