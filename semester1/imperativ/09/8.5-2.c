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
