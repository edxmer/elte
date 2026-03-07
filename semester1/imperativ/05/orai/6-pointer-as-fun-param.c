#include <stdio.h>
 
void init(int *p);

int main () {

   int s;
   init(&s);

   printf("Initialized value of s: %d\n", s );

   return 0;
}

/*

C-ben csak paraméter szerinti érték átadás van, nincs referencia szerinti érték átadás

*/

void init(int *p) { 
   scanf("%d", p);
   return;
}