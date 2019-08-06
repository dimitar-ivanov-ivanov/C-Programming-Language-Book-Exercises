#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

int getLine(char line[]);
void printLine(char line[],int len);
int countBrackets(char line[],int len);

int main() {
    int len;
    char line[MAXLEN];

    while((len = getLine(line)) > 0) {
        if(countBrackets(line,len) == 1) {
            printf("correct syntax\n");
        } else {
            printf("incorrect syntax\n");
        }
    }

    return 0;
}

int getLine(char line[]) {
    int c,i;
    for(i =0; i< MAXLEN -1 && ((c = getchar()) != EOF && c != '\n'); i++) {
        line[i] = c;
    }

    line[i] = '\0';
    return i;
}

void printLine(char line[],int len) {
    for(int i = 0; i< len && line[i] != '\0'; i++) {
        putchar(line[i]);
    }
    printf("\n");
}

int countBrackets(char line[],int len) {
    int wavyBracket,curlyBracket,squareBracket,c;
    wavyBracket = curlyBracket = squareBracket = 0;

    for(int i = 0; i < len; i++) {
        int c = line[i];
        switch(c) {
        case '{':
            curlyBracket++;
            break;
        case '(':
            wavyBracket++;
            break;
        case '[':
            squareBracket++;
            break;
        case '}':
            curlyBracket--;
            break;
        case ')':
            wavyBracket--;
            break;
        case ']':
            squareBracket--;
            break;
        default:
            break;
        }
    }

    if(wavyBracket + curlyBracket + squareBracket == 0) {
        return 1;
    }

    return 0;
}
