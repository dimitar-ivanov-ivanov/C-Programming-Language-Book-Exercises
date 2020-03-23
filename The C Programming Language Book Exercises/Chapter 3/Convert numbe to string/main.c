#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ito(int n,char s[]);

int main() {
    char s[1024] = "";
    int n = -120;
    ito(n,s);

    printf("%s",s);
    return 0;
}

void ito(int n,char s[]) {
    int i,sign;
    if((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if(sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    strrev(s);
}


