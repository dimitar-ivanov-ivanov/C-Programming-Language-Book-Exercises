#include <stdio.h>
#include <stdlib.h>

int main() {
    int c,;
    while((c = getchar()) != EOF) {
        if(c != '\0') {
            printf("%s",c);
        }
    }

    return 0;
}
