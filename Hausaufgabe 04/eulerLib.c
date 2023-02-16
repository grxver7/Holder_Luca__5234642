#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eulerLib.h"

#define NUMOFSTATES 2
#define APERIODICLIMIT 3 //Task 2

void rhsMSD(double *rhs, double *y) { // mass spring damper

    double m = 1.0;  // mass of object
    double c = 2;    // feder constant
    double d = 3; // damper constant

    double x = y[0]; // position
    double v = y[1]; // speed

    rhs[1] = -1 * ((d / m) * v + (c / m) * x);
    rhs[0] = v;
}

void eulerSettingsMSD(simHandle *handle) {
    handle->numOfStates = NUMOFSTATES;
    handle->f = rhsMSD;
    handle->stateVecInit = malloc(sizeof(double) * (handle->numOfStates));

    printf("Time of simulation (in s): \n");
    scanf("%lf", &handle->simTime);

    printf("Step size (in s): \n");
    scanf("%lf", &handle->stepSize);

    printf("Position(t = 0): \n");
    scanf("%lf", &handle->stateVecInit[0]);

    printf("Speed(v = 0): \n");
    scanf("%lf", &handle->stateVecInit[1]);

    errorHandlingInput(handle);

    handle->stateVec = malloc(sizeof(double) * handle->numOfStates);
    handle->derivStateVec = malloc(sizeof(double) * handle->numOfStates);

    for (int i = 0; i < handle->numOfStates; i++) {
        handle->stateVec[i] = 0;
        handle->derivStateVec[i] = 0;
    }
}

void eulerForward(simHandle *handle) {
    int numOfStates = handle->numOfStates;
    int integratorSteps = (int) ceil(handle->simTime / handle->stepSize);
    FILE *filePointer = fopen("simData.txt", "w");

    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < numOfStates; i++) {
        handle->stateVec[i] = handle->stateVecInit[i];
    }

    fprintf(filePointer, "%lf %lf %lf\n", 0.0, handle->stateVecInit[0], handle->stateVecInit[1]);
    for (int i = 1; i <= integratorSteps; i++) {

        handle->f(handle->derivStateVec, handle->stateVec);
        fprintf(filePointer, "%lf ", i * handle->stepSize);

        for (int j = 0; j < numOfStates; j++) {
            handle->f(handle->derivStateVec, handle->stateVec);
            handle->stateVec[j] += handle->stepSize * handle->derivStateVec[j];
            fprintf(filePointer, "%lf ", handle->stateVec[j]);
        }
        fprintf(filePointer, "\n");
    }
    fclose(filePointer);
    free(handle->stateVec);
    free(handle->derivStateVec);
}

void showResultsMSD() {
    FILE *gnuPlotPointer = popen("gnuplot -persistent", "w");
    fprintf(gnuPlotPointer, "set title \"Results of Simulation\"\n");
    fprintf(gnuPlotPointer, "set xlabel \"time in sec\"\n");
    fprintf(gnuPlotPointer, "set key on\n");
    fprintf(gnuPlotPointer,
            "plot 'simData.txt' using 1:2 with lines title \"position\", 'simData.txt' using 1:3 with lines title \"speed\"\n");
    pclose(gnuPlotPointer);
}

void errorHandlingInput (simHandle *handle) {
    if (handle->simTime<=0) {
        printf("In a time of 0, the object can't move!\n");
        printf("Your object has the position %lf and speed %lf \n", handle->stateVecInit[0], handle->stateVecInit[1]);
        exit(0);
    }
    if (handle->stepSize<=0) {
        printf("Warning, step size <= 0 isn't allowed!");
        exit(-1);
    }
}
