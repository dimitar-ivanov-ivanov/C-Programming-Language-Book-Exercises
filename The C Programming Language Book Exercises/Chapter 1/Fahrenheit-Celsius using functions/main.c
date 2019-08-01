#include <stdio.h>
#include <stdlib.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    int fahr;
    for(fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%d %6.1f\n",fahr,convertFahrenheitToCelsius(fahr));
    }
    return 0;
}

float convertFahrenheitToCelsius(int fahr) {
    return (5.0/9.0)* (fahr -32);
}
