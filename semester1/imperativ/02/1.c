#include <stdio.h>
#include <math.h>

int main() {

    // 1
    int n;
    printf("%d\n", n);
    
    // 2
    printf("szám 🐄: ");
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("\tpáros\n");
    else
        printf("\tpáratlan\n");

    // 3
    if (n > 0)
        printf("\tnagyobb mint 0\n");
    else if (n < 0)
        printf("\tkisebb mint 0\n");
    else
        printf("\tnulla\n");

    // 4
    int x = 9123;
    printf("%d\n", x);
    
    int y = 'x';
    printf("%d\n", y);
    
    int z = 1 == 1;
    printf("%d\n", z);
    
    //int u = "yo"; // error
    //printf("%d\n", u);
    printf("%d\n", sizeof(short));
    short s_min = -32768;
    short s_max = 32767;
    short s_p = s_max + 1;
    printf("%d\n", s_p);
    short avg = (s_min + s_max) / 2;
    printf("%d\n", avg);

    return 0;
}