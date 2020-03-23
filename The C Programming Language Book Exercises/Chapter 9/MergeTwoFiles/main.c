#include <stdio.h>
#include <stdlib.h>

#define LEN 100

int main(int argc,char *argv[]) {
    FILE *fp1,*fp2,*fp3;
    char str[LEN];
    int count = 0;

    if(argc != 3) {
        printf("Error in input");
        exit(1);
    }

    if((fp1 = fopen(argv[1],"r")) == NULL) {
        printf("Error trying to read the first file.");
        exit(1);
    }

    if((fp2 = fopen(argv[2],"r")) == NULL) {
        printf("Error trying to read the second file.");
        exit(1);
    }

    while(!feof(fp1)) {
        str[count++] = fgetc(fp1);
        if(ferror(fp1)) {
            printf("Error trying to get char from file 1.");
            exit(1);
        }
    }

    if(fclose(fp1) == EOF) {
        printf("Error trying to close the first file.");
        exit(1);
    }

    while(!feof(fp2)) {
        str[count++] = fgetc(fp2);
        if(ferror(fp2)) {
            printf("Error trying to get char from file 2.");
            exit(1);
        }
    }

    if(fclose(fp2) == EOF) {
        printf("Error trying to close the second file.");
        exit(1);
    }

    if((fp3 = fopen("third.txt","w")) == NULL) {
        printf("Error trying to write the third file.");
        exit(1);
    }

    for(int i = 0; i < count - 1; i++) {
        if(str[i] >=0) {
            fputc(str[i],fp3);
        }
    }

    if(fclose(fp3) == EOF) {
        printf("Error trying to close the third file.");
        exit(1);
    }




    return 0;
}
