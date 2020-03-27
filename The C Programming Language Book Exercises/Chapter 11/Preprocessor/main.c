#include <stdio.h>
#include <stdlib.h>

#define CHAR_SET 256

int main() {
    int i;
#if CHAR_SET == 256
    printf("Displaying full ASCII character set plus extensions");
#else
    printf("Displaying only ASCII character set.\n");
#endif // CHAR_SET

    for(i = 0; i < CHAR_SET; i++) {
        printf("%c",i);
    }
    return 0;
}
