#include <stdio.h>

#define BUFFER_SIZE 8
#define STR(x) #x
#define XSTR(x) STR(x)


int general(int* arr, int len, int (*f) (int, int, int)) {

    int out, i;
    
    for (i=0; i<len; ++i)
        out = (*f)(i, out, arr[i]);

    return out;

}


int sum(int i, int a, int b) {
    if (!i)
        return b;
    return a+b;
}

int prod(int i, int a, int b) {
    if (!i)
        return b;
    return a*b;
}

int count(int i, int a, int b) {
    if (!i)
        return 1;
    return a + 1;
}

int max(int i, int a, int b) {
    if (!i || b > a)
        return b;
    return a;

}

int min(int i, int a, int b) {
    if (!i || b < a)
        return b;
    return a;

}






int main() {

    // 1
    
    char buff[BUFFER_SIZE + 1];

    scanf("%" XSTR(BUFFER_SIZE) "s", buff);

    printf("%s\n", buff);
    

    // 2
    
    int v[] = {5, 1, 3, 6, 2, 4};
    int len = sizeof(v) / sizeof(*v);

    int vsum = general(v, len, sum);
    int vprod = general(v, len, prod);
    int vcount = general(v, len, count);
    int vmax = general(v, len, max);
    int vmin = general(v, len, min);


    printf("sum: %d\n", vsum);
    printf("prod: %d\n", vprod);
    printf("count: %d\n", vcount);
    printf("max: %d\n", vmax);
    printf("min: %d\n", vmin);



    return 0;
}
