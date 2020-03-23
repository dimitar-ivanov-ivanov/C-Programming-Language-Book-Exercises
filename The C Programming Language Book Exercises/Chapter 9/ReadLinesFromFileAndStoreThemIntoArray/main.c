#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

int main() {
    char ch,arr[LEN][LEN];
    char whitespaces[] = {'\n','\r','\t'};
    int i,j,flag;
    FILE *fp;

    i = j = flag = 0;

    if((fp = fopen("myfile.txt","rb")) == NULL) {
        printf("Problem accesing file.\n");
        exit(1);
    }

    while(!feof(fp)) {
        ch = fgetc(fp);
        if(ferror(fp)) {
            printf("Error reading  file.\n");
            exit(1);
        }

        for(int k = 0; k < strlen(whitespaces); k++) {
            if(ch == whitespaces[k]) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            flag = 0;
            i++;
            j= 0;
            continue;
        }
        arr[i][j++] = ch;
    }


    printf("d");
    for(int k = 0; k <= i; k++) {
        for(int p = 0; p < strlen(arr[i]); p++) {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
