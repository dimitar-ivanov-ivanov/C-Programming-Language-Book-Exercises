#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);

int main() {
    char s[] = "I am a good boy";
    reverse(s);
    printf("%s\n",s);
    return 0;
}

void reverse(char s[]) {
    for(int i = 0, j = strlen(s) -1; i<j; i++,j--) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
