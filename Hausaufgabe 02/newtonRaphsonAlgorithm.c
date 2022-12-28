#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functionF.h"

//Hauptprogramm
void newtonRaphsonMethod(double resultBefore, char selectedDerivation) {
    double resultFunction;
    double resultDerivation;
    double result=resultBefore;
    double stopValue=10e-10;;
    int counter=1;

    double (*getDerivation)(double);
    double (*getFunction)(double) = &functionF; //pointer to functionF

    if (selectedDerivation=='a') {
        getDerivation = &derivationFunctionAnalytic; //pointer to analytic derivation
    }
    else if(selectedDerivation=='n') {
        getDerivation = &derivationFunctionNumeric; //pointer to numeric derivation
    }
    else {
        printf("\nInvalid input");
        exit(-1); //invalid input
    }

    for (int i = 0; i < 1000; i++) {
        resultFunction=(*getFunction)(resultBefore);
        resultDerivation=(*getDerivation)(resultBefore);
        result=result-(resultFunction/resultDerivation); //newton raphson method result= x - (x sub n+1)

        if (resultFunction==0) { //values equal
            printf("\nThe zero of the function is %f", result);
            printf("\nYou needed %d iterations", counter);
            exit(0);
        }

        if (fabs(result-resultBefore) <= stopValue) { //value almost equal
            printf("\nThe zero of the function is approximately %f", result);
            printf("\nYou needed %d iterations", counter);
            exit(0);
        }
        resultBefore=result;
        counter++;
    }
    //reached limit of iterations
    printf("\nThe zero of the function is approximately %f", result);
    printf("\nYou stopped with %d iterations", counter);
    exit(0);
}