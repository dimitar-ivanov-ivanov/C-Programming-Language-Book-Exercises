#include <stdio.h>
#include <stdlib.h>

#define MINLEN 80
#define MAXLEN 1000


int getline(char s[]);
int printLine(char s[],int len);

int main() {
    int len;
    char line[MAXLEN];

    while((len = getline(line)) > 0) {
        if(len > MINLEN) {
            printLine(line,len);
        }
    }

    return 0;
}

int getline(char s[]) {
    int c,i;

    for(i = 0; i< MAXLEN - 1 && ((c = getchar()) != EOF && c != '\n'); i++) {
        s[i] = c;
    }

    s[i] = '\0';
    return i;
}

int printLine(char s[],int len) {
    int c,i;

    for(i = 0; i < len; i++) {
        c = s[i];
        putchar(s[i]);
    }

    printf("\n");
    return i;
}
