#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBase(char res[],int n,int base);

int main() {
    char res[1024] = "";
    int n =32;
    int base = 16;
    convertToBase(res,n,base);
    printf("%s\n",res);
    return 0;
}

void convertToBase(char res[],int n,int base) {
    int index = 0;
    while(n > 0) {
        int mod = n % base;
        if(mod >= 0 && mod <=9) {
            res[index++] = (mod + '0');
        } else {
            res[index++] = (mod - 10 + 'A');
        }
        n /= base;
    }

    strrev(res);
}
