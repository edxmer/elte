// 2025-10-12 18:21
#include <stdio.h>

int sum(int *arr, int len) {
    int result = 0;
    for (int i = 0; i < len; i++) {
        result += *(arr + i);
    }
    return result;
}

int main() {
    int numbers[] = {1,2,3,4,8,7,9,9,8,3,2,1,1,8,9,9,9,9,9};

    printf("%d az összeg\n", sum(
        numbers,
        sizeof(numbers)/sizeof(*numbers)
    ));

    return 0;
}