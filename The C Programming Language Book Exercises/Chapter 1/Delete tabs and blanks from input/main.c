#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int getLine(char line[]);
int removeBlanks(char to[],char from[],int len);
int printLineWithoutBlanks(char line[],int len);

int main() {

    int len;
    char line[MAXLEN], lineWithoutsBlanks[MAXLEN];

    while((len = getLine(line)) > 0) {
        int lenLineWithoutBlanks =  removeBlanks(lineWithoutsBlanks,line,len);
        printLineWithoutBlanks(lineWithoutsBlanks,lenLineWithoutBlanks);
    }

    return 0;
}

int getLine(char line[]) {
    int c,i;

    for(i = 0; i < MAXLEN - 1 && ((c = getchar()) != EOF && c != '\n'); i++) {
        line[i] = c;
    }

    line[i] = '\0';
    return i;
}

int removeBlanks(char to[],char from[],int len) {
    int j = 0;
    for(int i = 0; i < len; i++) {
        if(from[i] != '\t' && from[i] != ' ' &&& from[i] !='\0') {
            to[j] = from[i];
            j++;
        }
    }

    return j;
}

int printLineWithoutBlanks(char line[],int len) {
    for(int i = 0; i<len; i++) {
        putchar(line[i]);
    }

    printf("\n");
    return 0;
}
