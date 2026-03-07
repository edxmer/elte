// 2025-10-11 14:15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int a[101];
    int n = sizeof(a)/sizeof(*a);
    srand(time(NULL));

    for (int i = 0; i<101; i++)
        a[i] = rand()%1000;

    qsort(a,
        n,
        sizeof(*a),
        compare);
    
    
    int median = a[50];

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("A medián %d\n", median);
    return 0;
}