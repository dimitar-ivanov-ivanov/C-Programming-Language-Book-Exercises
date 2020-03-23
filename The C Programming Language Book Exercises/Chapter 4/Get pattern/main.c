#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 2

int getline(char line[],int max);
int strindex(char source[],char searcfor[]);

char pattern[] = "ould";

int main() {
    char line[MAXLINE];
    int found = 0;
    while(getline(line,MAXLINE) > 0) {
        if(strindex(line,pattern) >=0) {
            printf("%s",line);
            found++;
        }
    }
    return found;
}

int getline(char s[],int lim) {
    int c,i;
    i = 0;
    //EOF - '@'
    while(--lim > 0 && (c=getchar()) != '@' && c !='\n') {
        s[i++] = c;
    }
    if(c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[],char t[]) {
    int i,j,k;
    for(i = 0; s[i] != '\0'; i++) {
        for(j=i,k=0; t[k] !='\0' && s[j] == t[k];k++);
        if(k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
