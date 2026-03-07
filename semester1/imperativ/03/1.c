#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
    srand(time(NULL));
    int min = 0;
    int max = 100000;
    int number = rand()%(max+1-min);
    int tries = 0;
    
    int guess;

    do {
        tries++;

        scanf("%d", &guess);
        if (guess == number)
            printf("Kitaláltad a számot! %d próbálkozás kellett ehhez.\n", tries);
        else {
            //char text[] = (guess < number) ? "Nagyobb ennél a szám." : "Kisebb ennél a szám.";

            if (guess < number)
                printf("Nagyobb ennél a szám.\n");
            else
                printf("Kisebb ennél a szám.\n");
                
        }
    } while (guess != number);

}