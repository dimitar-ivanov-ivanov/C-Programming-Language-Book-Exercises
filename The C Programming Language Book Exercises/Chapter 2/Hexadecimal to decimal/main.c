#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexadecimalToDecimal(char hex[]);

int main() {
    char hex[2] = "1A";
    printf("%d",hexadecimalToDecimal(hex));
    return 0;
}

int hexadecimalToDecimal(char hex[]) {
    int len = strlen(hex);
    int dec = 0;

    // Initializing base value to 1, i.e 16^0
    int base = 1;

    // Remove one for \0 and another for the last item
    for(int i = len - 2; i>=0; i--) {

        // if character lies in '0'-'9', converting
        //it to integral 0-9 by subtracting 48 from
        // ASCII value.

        if(hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0')* base;
        }
        // if character lies in 'A'-'F' , converting
        // it to integral 10 - 15 by subtracting 55
        // from ASCII value
        else if (hex[i] >= 'A' && hex[i] <='F') {
            dec += (hex[i]  - 55) * base;
        }

        base = base * 16;
    }

    return dec;
}
