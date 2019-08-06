#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define ROWLEN 5

int getLine(char line[]);
void printLine(char line[],int len);
void seperateLine(char line[],int len);

int main() {
    int len;
    char line[MAXLEN];

    while((len = getLine(line)) > 0) {
        if(len > ROWLEN) {
            seperateLine(line,len);
        } else {
            printLine(line,len);
        }
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
        line[i] = '\0'; //clear array after every print
    }
    printf("\n");
}

void seperateLine(char line[],int len) {
    char currentRow[ROWLEN];
    int j = 0;

    for(int i=0; i < len; i++) {
        if(i > 0 && i % ROWLEN == 0) {
            printLine(currentRow,ROWLEN);
            j = 0;
        }
        currentRow[j] = line[i];
        j++;
    }

    //if we have some elements of the array full
    if(currentRow[0] != '\0') {
        printLine(currentRow,j);
    }
}
