#include "newtonRaphsonAlgorithmNumeric.h"
#include <stdio.h>
#include <stdlib.h>
#include "functionF.h"
#include <math.h>

void newtonRaphsonAlgorithmNumeric(double seed) {
    double resultFunction;
    double resultDerivation;
    double result;
    double resultBefore;
    int stopValue;
    int counter=1;
    resultBefore = seed;
    printf("\n%f", resultBefore);
    stopValue = pow(10, -10);
    printf("\n%d", stopValue);

    for (int i =1; i <=1000; i++) {
        double (*getFunction)(double) = &functionF; //pointer to function
        resultFunction=(*getFunction)(resultBefore);

        double (*getDerivation)(double) = &derivationFunctionNumeric;
        resultDerivation=(*getDerivation)(resultBefore);

        result=result-(resultFunction/resultDerivation);

        if (result == resultBefore) {
            printf("\nThe zero of the function is approximately %fl", result);
            printf("\nYou needed %d iterations", counter);
            exit(0);

        }
        if (result-resultBefore <= stopValue) {
            printf("\nThe zero of the function is approximately %fl", result);
            printf("\nYou needed %d iterations", counter);
            exit(0);
        }
        counter++;
    }
    printf("\nThe zero of the function is approximately %fl", result);
    printf("\nYou needed %d iterations", counter);
    exit(0);
}