#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int mycmp(char *str1, char *str2) {
    
    int i;

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i) {
        if (str1[i] != str2[i]) {
            return str1[i]-str2[i];
        }
    }
        return str1[i]-str2[i];

}

int mycpy(char *dest, char *src) {
    int i;
    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = src[i];

    return 1;
}

int main() {
    
    // 1. feladat

    char str1[1024];
    fgets(str1, sizeof(str1), stdin);

    int betuk, szavak;
    betuk = strlen(str1);
    szavak=0;

    for (int i = 0, prevWhitespace = 1; i < betuk-1; ++i) {
        if ( isspace( (unsigned char)str1[i] ) )
            prevWhitespace = 1;
        else { 
            if (prevWhitespace) ++szavak;
            prevWhitespace = 0;
        }
    }

    printf("Betuk: %d, szavak: %d\n", betuk, szavak);
    
    // 2. feladat
    
    char str2[1024];
    
    fgets(str2, sizeof(str1), stdin);
    
    int comp = strcmp(str1, str2);
    int mycomp = mycmp(str1, str2);
    
    printf("strcmp: %d ; mystrcmp: %d\n", comp, mycomp);
    
    
    // 3. feladat

    char copy[1024];
    char mycopy[1024];

    memset(str2, 'x',sizeof(str2));
    str2[50] = '\0';

    strcpy(copy, str2);
    mycpy(mycopy, str2);

    printf("strcpy: '%s'\n", copy);
    printf("mycpy : '%s'\n", mycopy);

    // 4. feladat
    char str[6] = "Hello";
    char *strPtr = "Hello";

    str[1] = 'a';
    // strPtr[1] = 'a';

    printf("'%s', '%s'\n", str, strPtr);

    // 5. feladat
    FILE *fp = fopen("random.txt", "r");
    FILE *outfp = fopen("randomout.txt", "w");
    if (fp == NULL || outfp == NULL) {
        printf("A fájl megnyitása sikertelen");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        for (int i = 0; line[i] != '\0'; ++i) {
            line[i] = toupper(line[i]);
        }
        printf("%s", line);
        fprintf(outfp, "%s", line);
    }

    fclose(fp);
    fclose(outfp);

    // 6. feladat

    FILE *numx = fopen("num1.txt", "r");
    FILE *numy = fopen("num2.txt", "r");
    FILE *numz = fopen("num3.txt", "w");

    if (numx == NULL || numy == NULL || numz == NULL) {
         printf("A fájl megnyitása sikertelen");
        return 1;
    }
    
    char line2[1024];
    int x;
    int y;
    while (fgets(line, sizeof(line), numx) && fgets(line2, sizeof(line2), numy)) {
        if ( sscanf(line, "%d", &x) == 1 && sscanf(line2, "%d", &y) == 1 )
            fprintf(numz, "%d\n", x * y);
    }
    
    fclose(numx);
    fclose(numy);
    fclose(numz);


    // 8. feladat
    // c = getchar();
    // c = fgetc(file stream (stdin/fp))
    

    
    





    


    return 0;  
}
