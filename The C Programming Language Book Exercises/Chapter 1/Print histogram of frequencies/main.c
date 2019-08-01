#include <stdio.h>
#include <stdlib.h>

/* for every ascii table character print how times it occurs using * */
int main() {
    int c,i,j;
    int asciiTable[128];

    for(i=0; i<128; i++) {
        asciiTable[i] = 0;
    }

    while((c = getchar()) != '`') {
        asciiTable[c]++;
    }

    for(i =1; i<128; i++) {
        for(j=0; j<asciiTable[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
