#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main() {
    char *p;

    if((p = malloc(SIZE)) == NULL) {
        printf("Allocation failed.");
        exit(1);
    }

    printf("Enter a string: ");
    gets(p);
    printf(p);
    free(p);


    return 0;
}
