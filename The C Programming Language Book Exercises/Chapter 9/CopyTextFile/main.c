#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char source[50];
    char destination[50];
    char strToWrite[50];
    char watch[50];
    int flag,i,count;
    char *c;
    FILE *fp1,*fp2;

    scanf("%s %s %s",source,destination,watch);

    if(!strcmp(watch,"watch")) {
        flag = 1;
    } else {
        flag = 0;
    }

    if((fp1 = fopen(source,"r")) == NULL) {
        printf("Error1");
        exit(1);
    }

    i = 0;
    while((c = fgetc(fp1)) != EOF) {
        strToWrite[i++] = c;
    }

    fclose(fp1);

    if((fp2 = fopen(destination,"w")) == NULL) {
        printf("Error2");
        exit(1);
    }

    for(i = 0;i < strlen(strToWrite); i++) {
        fputc(strToWrite[i],fp2);
        if(flag == 1){
            printf("%c",strToWrite[i]);
        }
    }


    return 0;
}
