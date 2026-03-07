#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int normalise(char *str) {

    for (int i = 0; str[i] != '\0'; ++i)
        if ( isspace( (unsigned char)str[i] ) ) str[i] = ' ';

    return 1;
}

int wordcount(char *str) {

    int isPrevSpace = 1;
    int wc = 0;

    for (int i = 0; str[i] != '\0'; ++i) {

        if (isPrevSpace && str[i] != ' ') {
            ++wc;
            isPrevSpace = 0;
        }
        else if (str[i] == ' ') {
            isPrevSpace = 1;
        }
    }

    return wc;
}

int* readnums(char *str, int len) {

    int n = 0;
    int pos = 0;
    int i = 0;
    char buff[32];

    int *nums = malloc(sizeof(int) * len);
    
    while ( sscanf(str + pos, "%s %n", buff, &n ) == 1 ) {
        nums[i++] = atoi(buff);
        pos += n;
    }
    
    return nums;
}


int comp (const void *a, const void *b) {
    return *(int*)a-*(int*)b;
}


int main() {
    
    FILE *in = fopen("in.txt", "r");
    FILE *out = fopen("output.txt", "w");
    if (in == NULL || out == NULL) {

        printf("A fájl megnyitása sikertelen.\n");

    }

    int i;
    char line[1024];

    int *nums;
    int num_count;
        

    // Read line-by-line
    
    while (fgets(line, sizeof(line), in)) {
        
        normalise(line);

        num_count = wordcount(line);

        nums = readnums(line, num_count);
        

        qsort(nums, num_count, sizeof(int), comp);

        for (i = 0; i < num_count; ++i) {
            fprintf(out, "%d ", nums[i]);
        }
        fputs("\n", out);
        
        free(nums);
    }


    fclose(in);
    fclose(out);
    return 0;

}
