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
