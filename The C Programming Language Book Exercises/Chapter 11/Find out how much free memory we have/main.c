#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(1000);
    long l = 0;

    while(p) {
        p = malloc(1000);
        if(p)
            l += 1000;
    }

    printf("Approximately %ld bytes of free memory: ",l);
    return 0;
}
