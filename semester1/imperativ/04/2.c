// 2025-09-29 15:02
#include <stdio.h>
#include <math.h>
#define SIZE 12

void fill_up(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}
int add_up(int *arr, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += arr[i];
    }
    return result;
}

int max(int *arr, int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > result)
            result = arr[i];
    }
    return result;
}

int min(int *arr, int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < result)
            result = arr[i];
    }
    return result;
}

int second_smallest(int *arr, int size) {
    int INTMAX = pow(2, sizeof(int)*8-1)-1;
    int result = INTMAX;

    int min_ = min(arr, size);
    for (int i = 0; i < size; i++) {

        //printf("- i:%d, arr[i]:%d, min_: %d", i, arr[i], min_);

        if (arr[i] < result && arr[i] != min_)
            result = arr[i];
    }

    if (result == INTMAX)
        result = arr[0];

    return result;
}

int weighted_sum(int* a, int* b, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += a[i] * b[i];
    }
    return result;
}

double weighted_average(int* a, int* b, int size) {
    int sum_ = 0;
    for (int i = 0; i < size; i++) {
        sum_ += a[i] * b[i];
    }
    int sum_w = add_up(b, size);
    float result = (float)(sum_)/(float)(sum_w);

    return result;
}

int main() {
    int a[SIZE];
    fill_up(a, SIZE); // put 0s

    a[4] = -2;
    a[2] = -5;


    int elso[] = {1, 2, 3, 4, 5};
    int masodik[] = {1, 1, 2, 3, 5};

    // Feldolgozás
    int sum = add_up(a, SIZE);
    int max_ = max(a, SIZE);
    int min_ = second_smallest(a, SIZE);
    int wsum = weighted_sum(elso, masodik, sizeof(elso)/sizeof(elso[0]));
    double wavg = weighted_average(elso, masodik, sizeof(elso)/sizeof(elso[0]));

    // Kiírás
    for (int i = 0; i < SIZE;i++)
        printf("\t%d -> %d\n", i, a[i]);
    printf("sum: %d\n", sum);
    printf("max: %d\n", max_);
    printf("second min: %d\n", min_);
    printf("weighted sum: %d\n", wsum);
    printf("weighted avg: %f\n", wavg);



    return 0;
}