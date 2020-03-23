#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Exercise 3-3. Write a function expand (s1, s2) that expands shorthand notations like a- z in the string s 1 into the equivalent complete list abc... xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
taken literally. 0
*/

void expand(char s1[],char s2[]);

int main() {
    char s1[] = "a-c a-b-c a-d0-9 -a-d";
    char s2[1024];
    expand(s1,s2);
    printf("%s\n",s2);
    return 0;
}

void expand(char s1[],char s2[]) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    for(int i = 0; i < n1 -2; i++) {
        char temp = s1;
        int c1 = s1[i];
        int c2 = s1[i+1];
        int c3 = s1[i+2];

        if((isdigit(c1) || isalpha(c1)) && c2 == '-' && (isdigit(c3) || isalpha(c3))) {
            for(int j = c1; j<=c3; j++) {
                char s3[2] = "";
                s3[0] = j;
                s3[1] ='\0';
                strcat(s2,s3);
            }
            i += 2;
            //s2[n2] = '\0';
        } else if(c1 == '-') {
            char s3[2] = "";
            s3[0] = '-';
            s3[1] ='\0';
            strcat(s2,s3);
        }
        //printf("a");
    }
}
