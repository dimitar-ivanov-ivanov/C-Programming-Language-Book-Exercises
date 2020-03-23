#include <stdio.h>
#include <stdlib.h>

int binsearch(int x,int v[],int n);

int main() {
    int x = 5;
    int n = 5;
    int v[n];

    for(int i = 0; i<n; i++) {
        v[i] = i + 1;
    }

    printf("index of number:%d",binsearch(x,v,n));
    return 0;
}

int binsearch(int x,int v[],int n) {
    int low,high,mid;
    low = 0;
    high = n -1;
    while(low <= high) {
        mid = (low + high) /2;
        if(x < v[mid]) {
            high = mid - 1;
        } else if(x > v[mid]) {
            low = mid + 1;
        } else {
            // found match
            return mid;
        }
    }

    // no match
    return -1;
}
