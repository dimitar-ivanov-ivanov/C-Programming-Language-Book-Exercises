#include <stdio.h>
#include <stdlib.h>

int main() {
    int c,i,j,letters;
    int arr[2];

    for(i=0; i<2; ++i) {
        arr[i] = 0;
    }

    letters = i = 0;
    while((c = getchar()) != EOF) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            letters++;
        } else {
            arr[i] = letters;
            letters = 0;
            i++;
        }
    }

    for(i = 0; i<2; i++) {
        for(j = 0; j<arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
