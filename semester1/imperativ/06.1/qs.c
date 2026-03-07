// https://chatgpt.com/c/68ee0f38-62e4-8326-aa76-0363c590f633

#include <stdio.h>


void swap(int*, int*);
int partition(int[], int, int);
int quicksort(int[], int, int);

int main() {

    int arr[] = {5,1,2,6,1,8,1,2,4,9,1,5,3};
    int n = sizeof(arr)/sizeof(*arr);

    quicksort(arr, 0, n-1);

    for (int *a; a < arr + n; a++) {
        printf("%d ", *a);
    }
    printf("\n");


}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b
    *b = temp;
}


// 7 5 2 3 
// low: 0
// high: 3

int partition(int[] arr, int low, int high) {

    int pivot = arr[high];
    
    int i = low + 1;

    //0, 1 , 2 , 3 
    for (int j = low; j < high; j ++) {
        if (arr[j] > pivot)
    }
    

}