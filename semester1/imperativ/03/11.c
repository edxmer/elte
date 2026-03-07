/*
Rajzold ki a Pascal háromszög első n sorát (n-et kérd be)!
*/

// A factorial miatt i=18 körül túlcsordul, pedig még a pascal háromszögben bőven nem éri el ezt a pontot.

#include <stdio.h>
#include <math.h>

unsigned long long fact(unsigned long long n) {
    if (n <= 1) // default case 
        return 1;

    return n * fact(n - 1);
}

unsigned long long nCr (unsigned long long n, unsigned long long r) { // Ismétlés nélküli kombináció
    return fact(n) / (fact(n-r)*fact(r));
}

/*

   x
  xxx
 xxxxx
xxxxxxx


    1
 1  2  1
1 3 3 1 1

*/



int main() {
    unsigned long long n; printf("n: "); scanf("%llu", &n);

    for (unsigned long long i = 0; i < n; ++i) {
        /*for (unsigned long long j = 0; j < (n-i); ++j)
            printf(" ");*/
        for (unsigned long long j = 0; j <= i; j++)
            printf("%llu ", nCr(i, j));
        printf("\n");


    }
}