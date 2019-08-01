#include <stdio.h>
#include <stdlib.h>

int main() {
    int c,whitespace;
    whitespace = 0;

    while((c = getchar()) != EOF) {
        if(c== '\n')
            ++whitespace;
        if(c== '\t')
            ++whitespace;
        if(c== '\0') //blank character
            ++whitespace;
    }

    printf("%d\n",whitespace);
    return 0;
}
