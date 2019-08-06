#include <stdio.h>
#include <stdlib.h>

int lower(int c);

int main() {
    char c = 'Z';
    printf("%c",lower(c));
    return 0;
}

int lower(int c) {
    if(c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}
