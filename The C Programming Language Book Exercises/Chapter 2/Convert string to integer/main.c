#include <stdio.h>
#include <stdlib.h>

int convertStringToInt(char s[]);

int main() {
    char s[2] = "10";
    printf("%d",convertStringToInt(s));
    return 0;
}

int convertStringToInt(char s[]) {
    int n =0;
    for(int i =0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = n * 10 + (s[i] - '0');
    }
    return n;
}
