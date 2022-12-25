#include <stdio.h>
#include "resultStruct.h"
#include "newtonRaphsonAlgorithm.h"

int main() {
    double seed;

    double a[4]; //pseudo

    printf("Seed for the algorithm: ");
    scanf("%lf", &seed);
    printf("%lf", seed);
    newtonRaphsonAlgorithm(seed);

    /*result iterations; //pseudo
    size_t sizeOfArray = sizeof(a)/sizeof(a[0]);
    for (int i=0; i < sizeOfArray; i++) {
        double value = a[i];
        printf("\nThe %d zero of the function has the value: %f", i, value);
    }
    printf("\nNumber of iterations: %d", iterations);*/
    return 0;
}
