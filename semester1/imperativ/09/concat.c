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
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int ispalindrom(char *str, int len) {
    


    for (int i = 0; i < len; ++i) {
        //printf("str i: %c, str len-i-1: %c\n", str[i], str[len-i-1]);
        if (str[i] != str[len-i-1])
            return 0;
    }

    return 1;
}


int maganhangzo(char c) {
    c = tolower(c);
    char mh[] = "aeiou";
    for (int i = 0; mh[i] != '\0'; ++i) {
        if (c == mh[i])
            return 1;
    }
    return 0;
}


int massalhangzo(char c) {
    c = tolower(c);
    if ('a' <= c && c <= 'z' && !maganhangzo(c))
        return 1;
    return 0;
}

int swap(char *a, char *b) {
    
    if (a == b) return 1;

    char temp = *a;
    *a = *b;
    *b = temp;
    
    return 1;
}

int permutations(char *str, int s, int e) {
    
    if (s+1 == e) {
        
        printf("%s\n", str);
        return 1;

    }

    for (int i = s; i < e; ++i) {
        swap(str+s, str+i);

        permutations(str, s+1, e);

        swap(str+s, str+i);
    }

    return 1;
    

}

long long unsigned int getoszam(char *onev) {

    long long unsigned int oszam = 0;
    
    for (int i = 0; onev[i] != '\0'; ++i ) {
        
        onev[i] = toupper(onev[i]);

        if (onev[i] < 'A' || 'Z' < onev[i])
            return 0;

        oszam += pow(26, i) * (onev[i] - 'A' + 1);
    }

    return oszam;
    

}


int cmp(const void *a, const void *b) { // Desc order
    return *(double*)b - *(double*)a;
}


double area(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return s*(s-a)*(s-b)*(s-c);
}


int istriangle(double a, double b, double c) {

    double s[] = {a, b, c};
    
    qsort(s, 3, sizeof(double), cmp);

    return s[0] < s[1] + s[2];
}

int main() {

    // Opcionalis feladatok
    
    // 1. Palindrom

    char str[1024];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);

    if (str[len-1] == '\n') { str[len-1] = '\0'; len-=1; }

    if (ispalindrom(str, len))
        printf("Ez egy palindróm.\n");
    else
        printf("Ez nem palindróm.\n");


    int mgh=0, msh=0;

    for (int i = 0; str[i] != '\0'; ++i) {
        mgh += maganhangzo(str[i]);
        msh += massalhangzo(str[i]);
    }

    printf("%d mgh., %d msh.\n", mgh, msh);

    char arviz[] = "árvíztűrőtükörfúrógép";
    printf("%lu byte\n", sizeof(arviz));
    
    // Haladó feladatok

    // 1. Permutációk

    printf("Permutációk:\n");
    permutations(str, 0, len);
    
    // 2. oszlopnév-oszlopszám
    
    char onev[32];
    fgets(onev, sizeof(onev), stdin);
    int olen = strlen(onev);
    if (onev[olen-1] == '\n') { onev[olen-1] = '\0'; olen -= 1; }

    long long unsigned int oszam;
    oszam = getoszam(onev);

    if (oszam) {
        printf("Az oszlopszám: %llu\n", oszam);
    }
    else {
        printf("Nem sikerült az oszlopszám konverzió.\n");
    }


   // 3. Haromszog
   
    double tri[] = {1, 4, 7, 5, 3, 9, 2};
    double trilen = sizeof(tri)/sizeof(*tri);
    
    
    double maxarea;
    int exists;
    int i, j, k, a;

    exists = 0;

    for (i = 0; i < trilen; ++i)
        for (j = i+1; j < trilen; ++j)
            for (k = j+1; k < trilen; ++k) {
                
                if (!istriangle(tri[i], tri[j], tri[k]));
                else if(!exists) {
                    exists = 1;
                    maxarea = area( tri[i], tri[j], tri[k] );
                }
                else if ( (a = area( tri[i], tri[j], tri[k] ) ) > maxarea) {
                    maxarea = a;
                    printf("%f, %f, %f\n", tri[i], tri[j], tri[k]);
                }

            }

    if (exists)
        printf("A legnagyobb területű háromszög: %f\n", maxarea);
    else
        printf("Nem létezik ilyen háromszög\n");
}
// 2025-11-10 14:29
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(char *str) {
    int len = strlen(str);
    char temp;
    int i;
    for (i = 0; i < len/2; ++i) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
    str[len] = '\0';
    return 1;
}

char* reverse_new(char *str) {
    int len = strlen(str);
    char *ptr = malloc( (len+1) * sizeof(char));

    int i;
    for (i = 0; i < len; ++i)
        ptr[i] = str[len-i-1];
    ptr[len] = '\0';
    
    return ptr;
}



int main() {
    char buff[21];
    fgets(buff, sizeof(buff), stdin);
    int len = strlen(buff);
    --len;
    buff[len] = '\0'; // \n eltüntetése
    char *ptr = malloc((len+1)*sizeof(char));
    int i;
    strcpy(ptr, buff);
    printf("%s\n", ptr);
    
    reverse(ptr);

    printf("%s\n", ptr);

    char *p2 = reverse_new(ptr);
    printf("%s\n", p2);


    free(p2);
    free(ptr);
    

    return 0;
}
// 2025-11-10 15:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    
    char line[1024];
    char words[5][256];

    fgets(line, sizeof(line), stdin);

    sscanf(line, "%s %s %s %s %s", words[0], words[1], words[2], words[3], words[4]);

    

    for (int i = 4; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    printf("\n");



    return 0;
}
// 2025-11-10 15:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    
    if (argc < 2) {
        printf("Nem adtál meg elég argumentumot.\n");
        return 1;
    }
    
    int wc;
    int i;
    char line[1024];
    char **words;
    int n, pos;

    wc = atoi(argv[1]);
    
    words = malloc(sizeof(char*) * wc);    

    for (i = 0; i < wc; ++i) {
        words[i] = malloc(sizeof(char) * 256);
    }
    
    

    fgets(line, sizeof(line), stdin);
    
    i = 0;
    pos = 0;
    while ( i < wc && sscanf(line + pos, "%s%n", words[i], &n) == 1) {
        ++i;
        pos += n;
    }


    for (int i = wc-1; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    printf("\n");

    

    return 0;
}
// 2025-11-10 15:06
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    

    char *line;
    int line_len;

    int wc;
    char **words;

    char ch;
    int n, pos;
    int i;
    int isPrevSpace;
        
    // Read input till EOF chacacter ^+d
    line_len = 1;
    line = malloc(sizeof(char)*line_len);
    i = 0;
    while ( (ch = getchar()) != EOF){
        if (i == line_len - 1) {
            line_len *= 2;
            line = realloc(line, sizeof(char)*line_len);
        }
        line[i] = ch;
        ++i;
    }
    line[line_len] = '\0';

    // Input normalizálása
    for (i = 0; line[i] != '\0'; ++i)
        if ( isspace( (unsigned char)line[i] ) )
            line[i] = ' ';

    // Szavak száma
    isPrevSpace = 1;
    wc = 0;
    for (i = 0; line[i] != '\0'; ++i) {
        if (isPrevSpace) {
            if ( line[i] != ' ' ) {
                isPrevSpace = 0;
                wc++;
            }
        }
        if ( line[i] == ' ' )
            isPrevSpace = 1;
    }

    // Szavak eltárolása
    
    words = malloc( sizeof(char*) * wc );
    for (i = 0; i < wc; ++i) {
        words[i] = malloc(sizeof(char) * 64);
    }
    
    n = 0;
    pos = 0;
    i = 0;
    while ( sscanf(line + pos, "%s%n", words[i++], &n) == 1 )
        pos+=n;


    // Fordítva kiírás:
    printf("\n");
    for (i = wc - 1; i >= 0; --i) {
        printf("%s ", words[i]);
    }
    printf("\n");



    // Memória felszabadítása
    for (i = 0; i < wc; ++i) {
        free(words[i]);
    }
    free(words);
    free(line);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>


int* paritas(int arr[], int len) {

    int *sorted = malloc(sizeof(int) * len);
    
    int left = 0;
    int right = len-1;
    
    int i;
    for (i = 0; i < len; ++i) {
        if ( arr[i] % 2 == 0 ) {
            sorted[left++] = arr[i];
        }
        else {
            sorted[right--] = arr[i];
        }
    }
    
    return sorted;
}


int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int len = sizeof(arr)/sizeof(*arr);
    int *s = paritas(arr, len);

    for (int i = 0; i < len; ++i) {
        printf("%d ", s[i]);
    } 
    printf("\n");


}
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
