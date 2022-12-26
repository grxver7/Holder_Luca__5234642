#include <stdio.h>
#include "newtonRaphsonAlgorithm.h"

int main() {
    double seed;
    char selectedDerivation;

    printf("Seed for the algorithm: ");
    scanf("%lf", &seed);

    printf("\nPrint [a] for the analytic derivation, \n or [n] for the numeric derivation: ");
    scanf(" %c", &selectedDerivation);
    newtonRaphsonMethod(seed, selectedDerivation);
    return 0;
}
