#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef long double bigFloat;
typedef unsigned long UL;

enum transport {car,train,airplane,bus} tp;

char trans[][20] = {
    "car", "train", "airplane","bus"
};

int main() {
    printf("Press a key to seleect transport: ");

    //generate random number everytime we start the program
    while(!kbhit())
        rand();
    getch(); //read and

    tp = rand() % 4;
    printf("%s\n",trans[tp]);
    tp = bus;
    printf("bus is %d\n",tp);

    UL a = 10;
    bigFloat bb = 10.132312;
    printf("%d %ld",a,bb);

    return 0;
}

void myfunc(const int *i) {
    *i = *i / 2;
}
