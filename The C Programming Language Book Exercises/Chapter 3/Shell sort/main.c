#include <stdio.h>
#include <stdlib.h>

void shellsort(int v[],int n);
void print(int v[],int n);

int main() {
    int v[4] = {4,3,2,1};
    int n = sizeof(v) / sizeof(int);
    shellsort(v,n);
    print(v,n);
    return 0;
}

void shellsort(int v[],int n) {
    for(int gap = n /2; gap >0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            for(int j = i - gap; j >=0 && v[j] > v[j+gap]; j-=gap) {
                int temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

void print(int v[],int n) {
    for(int i = 0; i<n; i++) {
        printf("%d\n",v[i]);
    }
}
