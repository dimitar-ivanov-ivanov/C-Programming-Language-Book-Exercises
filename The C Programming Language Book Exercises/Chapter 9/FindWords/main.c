#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char ch;
    int words = 0;
    int lines = 0;

    if((fp = fopen("myfile.txt","r")) == NULL) {
        printf("Error trying to open file.");
        exit(1);
    }

    while(!feof(fp)) {
        ch = fgetc(fp);
        if(ferror(fp)) {
            printf("Error trying to get character from file.");
            exit(1);
        }

        if (ch == '\n' || ch == '\0')
            lines++;

        /* Check words */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;

    }

    //if there is at least one word there is a line
    if(words > 0 && lines == 0) {
        lines = 1;
    }


    if(fclose(fp) == EOF) {
        printf("Error trying to close file");
        exit(1);
    }

    printf("%d %d",words,lines);

    return 0;
}
