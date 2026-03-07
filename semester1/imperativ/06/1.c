// 2025-10-13 14:12
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "/Users/edi/dev/studies/semester1/imperativ/6/test.txt"

void check_line(int, char*);

int main() {
    FILE *fp = fopen(FILE_PATH, "r");
    char buff[255];
    int i = 1;
    while (fgets(buff, sizeof(buff), fp)) {
        check_line(i, buff);
        i++;
    }

    fclose(fp);
    return 0;
}

int contains_nums(char *str) {

    while (*str != '\0') {
        if ('0' <= *str && *str <= '9')
            return 1;
        str++;
    }

    return 0;
}

void check_line(int i, char *line) {
    int length = strlen(line);
    if (line[length-1] == '\n')
    {
        line[length-1] = '\0';
        length -= 1;
    }

    printf("%d. sor (\"%s\"):\n", i, line);

    if (length > 5)
        printf("\t- 5 karakternél hosszabb sor\n");

    if (strchr(line, 'x'))
        printf("\t- van benne x karatker\n");

    if (strstr(line, "alma"))
        printf("\t- van benne alma szó\n");

    if (strcmp(line, "cica") == 0)
        printf("\t- ez cica szó\n");

    if (contains_nums(line))
        printf("\t- tartalmaz számokat\n");
}