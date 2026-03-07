// 2025-10-26 14:11
#include <stdio.h>

int search_(int x, int arr[], int n) {
    int sol = -1;
    do {
        ++sol;
    } while ( sol < n && arr[sol] != x);

    if (sol == n)
        return -1;
    else
        return sol;
}

int search(int x, int arr[], int n) {
    int i = 0;
    int index = -1;
    do {
        if (x == arr[i]) {
            index = i;
            break;
        }
        ++i;
    } while ( i < n);

    return index;
}

int main() {
    
    int arr[] = {1, 5, 2, 3, 8, 9, 12, 41, 1, 5, 7, 4};

    int ind = search(1, arr, sizeof(arr)/sizeof(*arr));

    printf("%d\n", ind);

    return 0;
}