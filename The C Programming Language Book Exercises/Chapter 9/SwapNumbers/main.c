#include <stdio.h>
#include <stdlib.h>

#define LEN 50

int main() {
    FILE *fp;
    int count = 0;
    char str[LEN];
    char strrev[LEN];

    if((fp = fopen("nums.txt","r")) ==NULL) {
        printf("Error trying to read file.");
        exit(1);
    }

    while(!feof(fp)) {
        str[count++] = fgetc(fp);
        if(ferror(fp)) {
            printf("Error trying to get char from file.");
            exit(1);
        }
    }

    if(fclose(fp) == EOF) {
        printf("Error trying to close file.");
        exit(1);
    }


    for(int i = 0; i < count-1; i++) {
        strrev[count - 1 - i - 1] = str[i];
    }

    if((fp = fopen("nums.txt","w")) ==NULL) {
        printf("Error trying to read file.");
        exit(1);
    }

    for(int i = 0; i < count-1; i++) {
        fputc(strrev[i],fp);
    }

    if(fclose(fp) == EOF) {
        printf("Error trying to close file.");
        exit(1);
    }

    return 0;
}
