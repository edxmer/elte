// 2025-10-12 21:31
#include <stdio.h>

int* a() {
    /*static*/ int arr[] = {1,2,3,4,5};

    return arr;
}

int main() {
    
    int *aa = a();

    for (int i = 0; i < 5; i++)
        printf("%d, ", aa[i]);
    printf("\n");

    int x[] = {1,2,4,1,2,3};
    int xx = 31231231;
    int xxx = 1231231;

    for (int i = 0; i < 5; i++)
        printf("%d, ", aa[i]);
    printf("\n");

    return 0;
}
