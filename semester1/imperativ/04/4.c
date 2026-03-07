// 2025-10-11 12:09
#include <stdio.h>
#include <string.h>

int elolrebb(char *a, char *b, int i, int lengthA, int lengthB);


int main() {
    char str1[1024];
    char str2[1024];


    printf("1. string: "); fgets(str1, sizeof(str1), stdin);
    printf("2. string: "); fgets(str2, sizeof(str2), stdin);


    int x = elolrebb(str1, 
                    str2, 
                    0, 
                    strlen(str1), 
                    strlen(str2));

    if (x == 1)
        printf("Az 1. string van előlrébb.\n");
    else if (x == 0)
        printf("Az 2. string van előlrébb.\n");
    else
        printf("A stringek egyenlők.\n");
        
    return 0;
}


int elolrebb(char *a, char *b, int i, int lengthA, int lengthB) {
    // 1 - a van előlrébb
    // 0 - b van előlrébb
    // -1 - egyenlőek
    if ( i == lengthA && i==lengthB )
        return -1;
    if ( i == lengthA && i < lengthB )
        return 1;
    if ( i < lengthA && i == lengthB )
        return 0;

    if (a[i] < b[i])
        return 1;
    if (b[i] < a[i])
        return 0;
    
    return elolrebb(a, b, i+1, lengthA, lengthB);
}