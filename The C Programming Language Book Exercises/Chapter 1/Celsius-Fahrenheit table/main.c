#include <stdio.h>
#include <stdlib.h>

int main() {
    float fahr;
    int lower,upper,step,celsius;
    lower = 0;
    upper = 40;
    step = 1;

    celsius = lower;
    printf("Table for Celsius to Fahrenheit convertion.\n");

    while(celsius <= upper) {
        fahr = celsius * 9.0/5.0 + 32;
        printf("%3d %6.1f\n",celsius,fahr);
        celsius = celsius + step;
    }

    return 0;
}
