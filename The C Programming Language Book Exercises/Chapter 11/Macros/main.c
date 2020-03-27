#include <stdio.h>
#include <stdlib.h>

#define SUM((i),(j)) (i) + (j)
#define RANGE((i),(min),(max)) ((i)<(min)) || ((i)>(max)) ? 1 : 0
#define MAX((i),(j)) (i)>(j) ? (i) : (j)

int main() {
    int sum = SUM(10,20);
    printf("%d\n",sum);

    int r;
    do{
        do{
            r = rand();
        } while(RANGE(r,1,100));
        printf("%d\n",r);
    } while(!kbhit());

    printf("%d\n",MAX(1,2));
    printf("%d\n",MAX(1,-1));

    return 0;
}
