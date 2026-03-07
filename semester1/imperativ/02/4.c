#include <stdio.h>
#include <math.h>

int main() {

    int n;
    scanf("%d", &n);

    
    /*
    
    12345
    length : 5
    divide 10^(5-1) » 1

    */

    int len = log10(n); // this is going to be len-1

    int reverse = 0;

    for (int i = len; i >= 0; i--) {
        int helyi = n/pow(10, i);
        n -= helyi * pow(10, i);
        reverse += helyi * pow(10, len - i);
    }

    printf("%d\n", reverse);

}