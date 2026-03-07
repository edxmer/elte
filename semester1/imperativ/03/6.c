#include <stdio.h>
#include <math.h>
#include <string.h>

// Ez teljesen az én megoldásom, de szerintem több részben jobb a gpt megoldása
// ChatGPT megoldása: https://chatgpt.com/c/68d7ea4f-7bd8-832c-a2eb-dc95ce70033a

int hex_to_dec(char c) {

    if (48 <= c && c <= 57) { // 0..9
        return (int)(c - 48);
    }

    if (97 <= c && c <= 102) { // 10..15
        return (int)(c - 97 + 10);
    }

    return -1;
}

int main() {
    char hex[11];
    printf("Hexadecimális szám (max 10 karakter):\n\t"); scanf("%10s", &hex);

    int length = strlen(hex);

    int dec = 0;

    for (int i = length - 1; i >= 0; i--) {

        int helyiertek = (length - 1) - i; // 0, 1, ...

        int ertek = hex_to_dec(hex[i]);

        if ( ertek == -1) // error történt
        {
            fprintf(stderr, "Hibás bemenet!\n");
            return -1;
        }

        dec += pow(16, helyiertek) * ertek;
    }

    printf("Decimálisba átkonvertálva %d az értéke.\n", dec);

}