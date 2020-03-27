#include <stdio.h>
#include <stdlib.h>

int sum(int a,int b);
int substract(int a,int b);
int mul(int a,int b);
int divide(int a,int b);

int main() {
    int result;
    int i,j,op;

    int (*p[4])(int x,int y) = {
     sum,substract,mul,divide
    };

    //p[0] = sum;
    //p[1] = substract;
    //p[2] = mul;
    //p[3] = divide;


    printf("Enter two numbers:\n");
    printf("0:Add 1:Substract 2:Multiply 3:Divide\n");

    do {
        scanf("%d %d",&i,&j);
        do {
            printf("Enter number of operation:");
            scanf("%d",&op);
        } while(op < 0 || op >3);

        result = p[op](i,j);
        printf("%d\n",result);
    } while(i > 0 && j > 0);

    return 0;
}

int sum(int a,int b) {
    return a + b;
}

int substract(int a,int b) {
    return a - b;
}

int mul(int a,int b) {
    return a * b;
}

int divide(int a,int b) {
    if (b)
        return a / b;

    return 0;
}
