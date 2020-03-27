#include <stdio.h>
#include <stdlib.h>

#define LEN 100
#define LIMIT 100

int comp(const void *i,const void *j);
void print(int arr[LEN]);

int main() {

    int arr[LEN], i,key;

    for(i = 0; i < LEN; i++) {
        arr[i] = rand() % LIMIT;
    }

    qsort(arr,LEN,sizeof(int),comp);
    //print(arr);
    scanf("%d",&key);

    int *p =  (int *)bsearch(&key,arr,LEN,sizeof(int),comp);

    if(p != NULL) {
        printf("%d",p - arr);
    } else {
        printf("Not found.");
    }
    return 0;
}

int comp(const void *i,const void *j) {
    return *(int *)i - *(int *)j;
}

void print(int arr[LEN]) {
    int i;
    for(i = 0; i < LEN; i++) {
        printf("%d\n",arr[i]);
    }
}
