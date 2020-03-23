#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
#define NAME 15

void getMarks(char str[LEN]);

int main() {
    FILE *fp;
    char str[LEN];

    if((fp = fopen("myfile.txt","r")) == NULL) {
        printf("Error reading file.");
        exit(1);
    }

    while(!feof(fp)) {
        fgets(str,'\n',fp);
        if(ferror(fp)) {
            printf("Error trying to get line from file.");
            exit(1);
        }
        getMarks(str);
    }

    if(fclose(fp) == EOF) {
        printf("Error trying to close file.");
        exit(1);
    }

    printf("da");
    return 0;
}

void getMarks(char str[LEN]) {
    int len = strlen(str);
    int whitespaceIndex = len;
    char name[NAME];
    char mark = str[len - 1];

    for(int i = 0; i < len - 1; i++) {
        name[i] = str[i];
    }

    printf("%s %d\n",name,mark);
}
