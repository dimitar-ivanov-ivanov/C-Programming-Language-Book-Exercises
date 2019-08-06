#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int getLine(char line[]);
void printLine(char line[],int len);
int detectComments(char line[],char lineWithNoComments[],int len);

int main() {
    int len;
    char line[MAXLEN],lineWithNoComments[MAXLEN];

    while((len = getLine(line)) > 0) {
        int noCommentsLen =   detectComments(line,lineWithNoComments,len);
        printLine(lineWithNoComments,noCommentsLen);
    }

    return 0;
}

int getLine(char line[]) {
    int c,i;
    for(i =0; i< MAXLEN -1 && ((c = getchar()) != EOF && c != '\n'); i++) {
        line[i] = c;
    }

    line[i] = '\0';
    return i;
}

void printLine(char line[],int len) {
    for(int i = 0; i< len && line[i] != '\0'; i++) {
        putchar(line[i]);
    }
    printf("\n");
}

int detectComments(char line[],char lineWithNoComments[],int len) {
    int k = 0;

    for(int i =0; i<len-1; i++) {
        if(line[i] == '/' && line[i + 1] == '/') {
            for(int j = i+2; j<len -1 ; j++) {
                if(line[j] == '/' && line[j+1] == '/') {
                    i = j+2;
                }
            }
        } else {
            lineWithNoComments[k++] = line[i];
        }
    }

    lineWithNoComments[k] = '\0';
    return k;
}
