// 2025-10-06 14:49
#include <stdio.h>



void print_arr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size-1; i++)
        printf("%d, ", arr[i]);
    printf("%d]\n", arr[size-1]);
}



void swap(int *arr, int i, int j);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};

    print_arr(arr, sizeof(arr)/sizeof(*arr));

    swap(arr, 1, 3);

    print_arr(arr, sizeof(arr)/sizeof(*arr));

    return 0;
}

void swap(int *arr, int i, int j) {
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;
}