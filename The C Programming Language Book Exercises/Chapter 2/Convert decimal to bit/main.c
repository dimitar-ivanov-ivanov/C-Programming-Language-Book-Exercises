#include <stdio.h>
#include <stdlib.h>

int decimalToBit(int k);

int main() {
    printf("%d",decimalToBit(10));
    return 0;
}

int decimalToBit(int k) {
    if(k == 0)
        return 0;
    if(k == 1)
        return 1;

    return (k % 2) + 10 * decimalToBit(k /2);
}
