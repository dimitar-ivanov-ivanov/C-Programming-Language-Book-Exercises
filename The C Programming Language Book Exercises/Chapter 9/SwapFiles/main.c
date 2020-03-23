#include <stdio.h>
#include <stdlib.h>

#define LEN 50

int main(int argc,char *argv[]) {
    FILE *fp1,*fp2;
    char str[LEN];
    int count = 0;

    if(argc !=3) {
        printf("Usage copy <source> <destination>\n");
        exit(1);
    }

    if((fp1 = fopen(argv[1],"rb")) ==NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    //read first file content
    while(!feof(fp1)) {
        str[count++] = fgetc(fp1);
        if(ferror(fp1)) {
            printf("Error reading first file.\n");
            exit(1);
        }
    }


    if(fclose(fp1) == EOF) {
        printf("Error closing first file.\n");
        exit(1);
    }

    if((fp1 = fopen(argv[1],"wb")) ==NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    if((fp2 = fopen(argv[2],"rb")) ==NULL) {
        printf("Cannot open destination file.\n");
        exit(1);
    }

    //copy second file content to first file content
    while(!feof(fp2)) {
        fputc(fgetc(fp2),fp1);
        if(ferror(fp2)) {
            printf("Error reading second file.\n");
            exit(1);
        }
    }

    if(fclose(fp1) == EOF) {
        printf("Error closing first file.\n");
        exit(1);
    }

    if(fclose(fp2) == EOF) {
        printf("Error closing second file.\n");
        exit(1);
    }


    //write first file content on second file
    if((fp2 = fopen(argv[2],"wb")) ==NULL) {
        printf("Cannot open destination file.\n");
        exit(1);
    }

    for(int i = 0; i < count; i++) {
        fputc(str[i],fp2);
    }

    if(fclose(fp2) == EOF) {
        printf("Error closing second file.\n");
        exit(1);
    }

    return 0;
}
