#include <stdio.h>
#include <stdlib.h>

void ito(int n,char s[],int givenWidth);

int main() {
    int n = -120;
    char s[1024] = "";
    int givenWidth= 5;
    ito(n,s,givenWidth);
    printf("%s\n",s);
    return 0;
}

void ito(int n,char s[],int givenWidth) {
    int i,sign;
    if((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if(n < givenWidth) {
        for(; i<= givenWidth; i++) {
            s[i++] = '0';
        }
    }
    if(sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';
    strrev(s);
}
