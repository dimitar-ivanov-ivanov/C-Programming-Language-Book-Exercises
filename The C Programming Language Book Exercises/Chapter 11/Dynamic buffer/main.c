#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int c = 1;
    int n = 10;
    double *p;
    FILE *fp;

    p = malloc(n* sizeof(double));
    if(!p) {
        printf("Allocation error.");
        exit(1);
    }

    for(i = 0; i < n; i++) {
        scanf("%lf",&p[i]);
    }

    if((fp = fopen("myfile.txt","wb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    if(fwrite(p,10*sizeof(double),1,fp) != 1) {
        printf("Write error.\n");
        exit(1);
    }

    fclose(fp);

    free(p);

    p = malloc(10 * sizeof(double));
    if(!p) {
        printf("Allocation error.");
        exit(1);
    }

    if((fp = fopen("myfile.txt","rb")) == NULL) {
        printf("Read error.\n");
        exit(1);
    }

    if(fread(p,10*sizeof(double),1,fp) != 1){
        printf("Read error.\n");
        exit(1);
    }

    fclose(fp);

    for(i = 0; i < n; i++) {
        printf("%f\n",p[i]);
    }

    free(p);

    return 0;
}
