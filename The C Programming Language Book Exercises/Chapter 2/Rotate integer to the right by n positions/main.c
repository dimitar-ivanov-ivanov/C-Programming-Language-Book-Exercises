#include <stdio.h>
#include <stdlib.h>

int rightrot(x,n);
int decimalToBit(int k);

int main() {
    printf("%d\n",rightrot(100,2));
    return 0;
}

int rightrot(int x,int n) {
    return x >> n;
}

int decimalToBit(int k) {
    if(k == 0)
        return 0;
    if(k == 1)
        return 1;

    return (k % 2) + 10 * decimalToBit(k /2);
}
