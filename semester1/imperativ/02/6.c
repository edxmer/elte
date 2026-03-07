// Legnagyobb közös osztó

#include<stdio.h>

int main() {

    int a, b;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    while (a != b) {
        if (a > b) {
            int temp;
            temp = b;
            b = a;
            a = temp;
        }
        b -= a;
    }

    printf("%d a legnagyobb közös osztó.\n", b);

}