#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {

    FILE *fp;
    int count = 0;
    char current;

    if(argc != 2) {
        printf("Count bytes of <file 1>\n");
        exit(1);
    }

    if((fp = fopen(argv[1],"rb")) ==NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while(feof(fp)) {
        current = fgetc(fp);
        if(ferror(fp)) {
            printf("Error reading file.\n");
            exit(1);
        }
        count += current;
    }

     if(fclose(fp) == EOF) {
        printf("Error closing file.\n");
        exit(1);
    }


    printf("%d",count);
    return 0;
}
