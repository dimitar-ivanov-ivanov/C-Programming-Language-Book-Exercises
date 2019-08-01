#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getline(char s[]);
void copy(char to[],char from[]);

int main() {

    int len,max;
    char line[MAXLINE],longest[MAXLINE];

    max = 0;
    while((len = getline(line)) > 0) {
        if(len > max) {
            max = len;
            copy(longest,line);
        }
    }
    if(max > 0) {
        printf("%s",longest);
    }
    return 0;
}

int getline(char s[]) {
    int c,i;
    for(i=0; i<MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[],char from[]) {
    int i;
    i =0;
    while((to[i] = from[i]) != '\0'){
        i++;
    }
}
