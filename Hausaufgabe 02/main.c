#include <stdio.h>
#include "newtonRaphsonAlgorithm.h"
#include "newtonRaphsonAlgorithmNumeric.h"

int main() {
    double seed;
    char derivationOutput;

    printf("Seed for the algorithm: ");
    scanf("%lf", &seed);
    printf("%lf", seed);

    printf("Print [a] for the analytic Derivation, \n or [n] for the numeric Derivation: ");
    scanf("%c", &derivationOutput);
    printf("%c", derivationOutput);
    if (derivationOutput=='a') {
        newtonRaphsonAlgorithm(seed);
    }
    else if (derivationOutput=='n') {
        newtonRaphsonAlgorithmNumeric(seed);
    }
    else {
        printf("Invalid input --> restart calculator");
        main();
    }

    return 0;
}
