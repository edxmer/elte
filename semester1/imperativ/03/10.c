/*
Deklarálj egy unsigned int típusú változót, és csináld végig ezzel is az előző feladat lépéseit.
*/

#include <stdio.h>
#include <math.h>

int main(){
    unsigned int n;
    n = pow(2, sizeof(unsigned int)*8) - 1;

    printf("n: %u\n", n);

    n += 1;

    printf("n+1: %u\n", n);
    
}