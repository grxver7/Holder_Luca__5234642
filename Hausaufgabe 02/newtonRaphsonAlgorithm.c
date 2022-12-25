#include <stdio.h>
#include "newtonRaphsonAlgorithm.h"
#include "functionF.h"

double newtonRaphsonAlgorithm (double seed) {
    double result;
    printf("\n%f", seed);
    double (*getFunction)(double) = &functionF; //pointer to function
    result=(*getFunction)(seed);
    printf("\n%f", result);

    double (*getDerivation)(double) = &derivationFunctionF;
    result=(*getDerivation)(seed);
    printf("\n%f", result);
    return 0;
}