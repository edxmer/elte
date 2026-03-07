#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define FILE_PATH "input.txt"



int main(void) {
    
    FILE *f;
    char buff[32];
    int num_of_zeros;
    int position;    
    int dir_i;
    char dir_c;
    int amount;
    int prev_pos;

    int new_pos_no_modulo;
    int t;

    num_of_zeros = 0;
    position = 50;

    f = fopen(FILE_PATH, "r");

    while (fgets(buff, sizeof(buff), f) && sscanf(buff, "%c%d", &dir_c, &amount) == 2) {
        
        dir_i = dir_c == 'R' ? 1 : -1;


        prev_pos = position;
        new_pos_no_modulo = (position + amount*dir_i);

        position = (new_pos_no_modulo % 100 + 100) % 100;

        if (prev_pos == 0 && dir_i < 0)
                new_pos_no_modulo += 100;
        
        t = strlen(buff) - 1;
        if (buff[t] == '\n') buff[t] = '\0';
        printf("%10s, %d, %d\n", buff, dir_i* amount, position);
        
        
        if ( (position == 0 || new_pos_no_modulo <= 0 || new_pos_no_modulo >= 100) && printf("!!!\n"))
            num_of_zeros += (int)floor((double)new_pos_no_modulo / 100.0) + 1;

    }

    printf("%d\n", num_of_zeros);

    fclose(f);
    return 0;
}
