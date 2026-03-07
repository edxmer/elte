#include <stdio.h>
#include <stdlib.h>


int* paritas(int arr[], int len) {

    int *sorted = malloc(sizeof(int) * len);
    
    int left = 0;
    int right = len-1;
    
    int i;
    for (i = 0; i < len; ++i) {
        if ( arr[i] % 2 == 0 ) {
            sorted[left++] = arr[i];
        }
        else {
            sorted[right--] = arr[i];
        }
    }
    
    return sorted;
}


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int len = sizeof(arr)/sizeof(*arr);
    int *s = paritas(arr, len);

    for (int i = 0; i < len; ++i) {
        printf("%d ", s[i]);
    } 
    printf("\n");


}
