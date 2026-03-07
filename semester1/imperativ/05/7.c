// 2025-10-12 21:23
#include <stdio.h>

int sum(int *first, int *afterlast) {
    int result = 0;
    for (int *i = first; i < afterlast; i += 1) {
        result += *i;
    }
    return result;
}

int main() {
    int numbers[] = {1,2,3,4,8,7,9,9,8,3,2,1,1,8,9,9,9,9,9};

    printf("%d az összeg\n", sum(
        numbers,
        numbers + sizeof(numbers)/sizeof(*numbers)
    ));

    return 0;
}