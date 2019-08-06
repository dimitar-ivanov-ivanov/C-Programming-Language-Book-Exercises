#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze(char s[],char t[],char finalS[]);

int main() {
    char s[] = "aad";
    char t[] = "ab";
    char finalS[50];
    squeeze(s,t,finalS);
    printf("%s",finalS);
    return 0;
}

void squeeze(char s[],char t[],char finalS[]) {
    int b,len = 0;
    for(int i = 0; s[i] != '\0'; i++) {
        //printf("%c",s[i]);
        for(int j = 0; t[j] != '\0'; j++) {
            //printf("%c",s[i]);
            if(s[i] == t[j]) {
                b = 1; //there is a match dont assing s[i]
                break;
            }
        }
        // there is no match assing s[i]
        if(b == 0) {
            len = strlen(finalS);
            finalS[len] = s[i];
            finalS[len + 1] = '\0';
        }
        b = 0;
    }
}
