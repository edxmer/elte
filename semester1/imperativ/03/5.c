// Gyakorló feladatok

// kitalalo obfuszkalasa

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0

int get_target(int min, int max);
int guessing(); // used as boolean 0, or 1 return
int evaluate(int guess, int number);


int main() {
    const unsigned char d = 'd';
    int number = get_target(MIN, (int)d);
    unsigned short tries = 'a' - 97;

    while ( evaluate( guessing() , number) ) {
        ++tries; tries++; tries--;
    }

    printf("Kitaláltad a számot! %d próbálkozás kellett ehhez.\n", tries);

    return 0;
}

int get_target(int min, int max) {
    srand(time(NULL));

    return rand()%(max+1-min);
}

int guessing() {
    int guess;
    printf("Mondj egy számot:");
    scanf("%d", &guess);
    return guess;
}

int evaluate(int guess, int number) {
    if (guess == number)
        return 0;
    else {
        if (guess < number)
            printf("Nagyobb ennél a szám.\n");
        else
            printf("Kisebb ennél a szám.\n");
        return 1;
    }
}