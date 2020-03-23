#include <stdio.h>
#include <stdlib.h>

int toLower(int c);

int main() {
    char c = 'z';
    printf("%c\n",toLower(c));
    return 0;
}

int toLower(int c) {
    return (c >= 'A' && c <= 'Z' )? (c + 'a' - 'A') : c;
}
