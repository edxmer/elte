/*
Deklarálj egy int típusú változót. Számold ki, hogy mekkora lehet a legnagyobb érték, amit el lehet ebben tárolni. 
Add értékül a változónak ezt a számot, majd egy következő utasításban adj hozzá egyet. Írd ki a megnövelt értéket.
*/

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    n = pow(2, sizeof(int)*8-1) - 1;

    printf("n: %d\n", n);

    n += 1;

    printf("n+1: %d\n", n);

}