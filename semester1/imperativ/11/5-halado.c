#include <stdio.h>
#include <stdlib.h>

typedef struct Dynamic Dynamic;

struct Dynamic {
    int *values;
    int n;
    int capacity;
};

Dynamic construct_dynamic(int cap) {
    Dynamic arr;
    arr.n = 0;
    arr.capacity = cap;
    arr.values = (int*) calloc(arr.capacity, sizeof(int));

    return arr;
}

void add(Dynamic* arr, int x) {
    
    if (arr->n >= arr->capacity) {
        arr->capacity *= 2;
        arr->values = realloc(arr->values, arr->capacity);
    }
    
    arr->values[arr->n] = x;
    arr->n ++;
}

void free_dynamic(Dynamic* arr) {
    free(arr->values);
    arr->n = 0;
    arr->capacity = 0;
}


void print_dynamic(Dynamic* arr) {
    int i;
    
    printf("{");
    for (i = 0; i < arr->n - 1; ++i)
        printf("%d, ", arr->values[i]);
    if (i == arr->n - 1)
        printf("%d", arr->values[i]);
    printf("}\n");

}


int main(void) {
    Dynamic arr = construct_dynamic(4);

    add(&arr, 4);
    add(&arr, 3);
    add(&arr, -51);
    add(&arr, 123);
    add(&arr, 45);

    print_dynamic(&arr);


}
