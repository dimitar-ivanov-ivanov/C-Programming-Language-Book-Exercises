#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int getLine(char line[]);
int reverseLine(char line[],char reversedLine[],int len);
int printReverseLine(char reversedLine[],int len);

int main() {
    int len;
    char line[MAXLEN],reversedLine[MAXLEN];

    while((len = getLine(line)) > 0) {
        reverseLine(line,reversedLine,len);
        printReverseLine(reversedLine,len);
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

int reverseLine(char line[],char reversedLine[],int len) {
    for(int i =0,j = len - 1; i < len; i++,j--)
        reversedLine[j] = line[i];

    return 0;
}

int printReverseLine(char reversedLine[],int len) {
    for(int i = 0;i< len;i++){
        putchar(reversedLine[i]);
    }
    printf("\n");
    return 0;
}
