#include <stdio.h>
#include <stdlib.h>

int main() {
    long nc;
    nc = 0;
    while(getchar() != EOF) {
        ++nc;
    }

    printf("%1d\n",nc);
    return 0;
}
