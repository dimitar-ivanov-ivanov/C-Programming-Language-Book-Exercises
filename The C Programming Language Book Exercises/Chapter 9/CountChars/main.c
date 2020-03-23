#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char c;
    int i;
    int letters['Z' + 1];

    for(i = 0; i <= 'Z'; i++) {
        letters[i] = 0;
    }

    if((fp = fopen("myfile.txt","r")) == NULL) {
        printf("Error");
        exit(1);
    }

    while((c = fgetc(fp)) != EOF) {
        if(c <= 'z') {
            if(c >= 'a' && c <= 'z') {
                letters[c - ('a' - 'A')]++;
            } else if(c >= 'A' && c <= 'Z')  {
                letters[c]++;
            }
        }
    }
    fclose(fp);

    for(i = 'A'; i <= 'Z'; i++) {
        printf("%c : %d\n",i,letters[i]);
    }

    return 0;
}
