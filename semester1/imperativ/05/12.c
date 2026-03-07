// 2025-10-13 9:32
// Gyakorlo feladat 1
#include <stdio.h>

int* maxptr(int *arr, int length);


int main() {
    // 1
    int arr[] = {1,2,5,1,2,5,7,98,1,6,1,-1,4,84,192,-999};

    int *max = maxptr(arr, sizeof(arr)/sizeof(*arr));

    printf("normal -> pointer: %p\tvalue: %d\n", max, *max);

    // 2

    int *halfmax = maxptr(arr, sizeof(arr)/sizeof(*arr) / 2);

    printf("half -> pointer: %p\tvalue: %d\n", halfmax, *halfmax);

    // 3
    int a = 8;

    int *single = maxptr(&a, 1);

    printf("single -> pointer: %p\tvalue: %d\n", single, *single);

    return 0;
}

int* maxptr(int *arr, int length) {

    int *result = arr;

    for (int *i = arr; i < arr+length; i++) {
        if (*i > *result) {
            result = i;
        }
    }

    return result;

}