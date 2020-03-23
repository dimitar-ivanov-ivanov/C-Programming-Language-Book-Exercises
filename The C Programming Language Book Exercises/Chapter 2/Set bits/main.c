#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int setbits(int x,int p,int n,int y);
int decimalToBit(int k);

int main() {
    setbits(1000,2,2,8);
    return 0;
}

//set the n bits after p to the exact n bits after y
int setbits(int x,int p,int n,int y) {
    //1111101000
    //
    char str[1000];

    for(int i = 0; i< 1; i++) {
        int a = decimalToBit(x);
        sprintf(str, "%d", a);
        int len = strlen(str);

        printf("%d %d\n",a,len);

        //in order to get p,we move the bits to len - p
        //if we want to get the bit to the right then each time remove i
        //if we want to get the bit to the left then each time add i
        int getPBit = (x >> (len - p - i)) & 1;
        int getYBit = (x >> (len - y - i)) & 1;
        int mask = getYBit << (len - p - i);

        //get the y bit move it to the p position and use or to set it
        if(mask == 1) {
            // if p bit is 0 and y is 1 p bit becomes 1
            // if p bit is 1 and y is 1 p stays 1
            x |= mask;
        } else if(mask == 0) {
            //we invert since if we have 0000 everything in p becoemes 0
            //
            // if p bit is 0 and y is 0
            // if p bit is 1 and y is 0
            x &= ~mask;
        }

        printf("%d %d\n",len - p - i,len - y - i);
        printf("%d\n",getPBit);
        printf("%d\n",getYBit);
        printf("%d\n",mask);

        a = decimalToBit(x);
        sprintf(str, "%d", a);
        len = strlen(str);
        printf("%d %d\n",a,len);
    }

    return x;
}

int decimalToBit(int k) {
    if(k == 0)
        return 0;
    if(k == 1)
        return 1;

    return (k % 2) + 10 * decimalToBit(k /2);
}
