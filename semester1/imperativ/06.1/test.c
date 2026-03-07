// 2025-10-14 11:29
#include <stdio.h>

int main() {
    int t[] = {6, 2, 8, 7, 3}; 
    int* p = NULL;
    for (int i = 0; i < 5; ++i)
        if (t[i] % 2 == 1) 
            p = &t[i]; 
    if (p) 
        printf("Utolsó páratlan szám: %d\n", *p); 
    else
        printf("Nincs páratlan szám\n"); 

    return 0;
}