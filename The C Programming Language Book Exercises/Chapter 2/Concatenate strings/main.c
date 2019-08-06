#include <stdio.h>
#include <stdlib.h>

void strcat(char s[],char t[]);

int main() {
    char s[] = "ab";
    char t[] = "cd";
    strcat(s,t);
    printf("%s",s);
    return 0;
}

void strcat(char s[],char t[]) {
    int i,j;
    i = j = 0;
    //find end of s
    while(s[i] !='\0')
        i++;

    //copy
    while((s[i++] = t[j++]) != '\0') ;

}
