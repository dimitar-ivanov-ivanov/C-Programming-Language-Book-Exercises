#include <stdio.h>
#include <stdlib.h>

void invert(int x,int p,int n);
int decimalToBit(int k);

int main() {
    invert(10,2,3);
    return 0;
}

void invert(int x,int p,int n) {
    char str[1000];

    for(int i =0; i<n; i++) {
        int a = decimalToBit(x);
        sprintf(str, "%d", a);
        int len = strlen(str);

        printf("%d %d\n",a,len);

        //turn the bit around
        x ^= (1 << p - i);
        a = decimalToBit(x);
        sprintf(str, "%d", a);
        len = strlen(str);

        printf("%d %d\n",a,len);
        printf("-----------------\n");
    }
}

int decimalToBit(int k) {
    if(k == 0)
        return 0;
    if(k == 1)
        return 1;

    return (k % 2) + 10 * decimalToBit(k /2);
}
