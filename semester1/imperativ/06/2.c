#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int a, b;
    int i;
    int sol;

    if (argc == 3) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
        sol = 0;
        for (i = 0; i < b; ++i) {
            sol += a;
        }
        printf("A megoldás: %d\n", sol);
    }
    else {
        printf("Nem jó az argumentumszám.\n");
        return 1;
    }
}