#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eulerLib.h"

#define NUMOFSTATES 2

void rhsMSD(double *rhs, double *y) { // mass spring damper

    double m = 1.0;  // mass of object
    double c = 5;    // feder constant
    double d = 0.25; // damper constant

    double x = y[0]; // position
    double v = y[1]; // speed

    /*calc derivatives and store in rhs*/
    rhs[0] = v;
    rhs[1] = -1 * ((d / m) * v + (c / m) * x);
}

void eulerSettingsMSD(simHandle *handle) {
    /*num of states*/
    handle->numOfStates = NUMOFSTATES;

    /*right hand site*/
    handle->f = rhsMSD;

    /*reserve storage for init state vec*/
    handle->stateVecInit = malloc(sizeof(double) * (handle->numOfStates));

    /*get Userinputs*/
    printf("Simtime (in s): \n");
    handle->simTime = 5;
    //scanf("%lf", &handle->simTime);

    printf("StepSize (in s): \n");
    handle->stepSize = 0.2;
    //scanf("%lf", &handle->stepSize);

    printf("position(t = 0): \n");
    handle->stateVecInit[0] = 1;
    //scanf("%lf", &handle->stateVecInit[0]);

    printf("speed(v = 0): \n");
    handle->stateVecInit[1] = 0;
    //scanf("%lf", &handle->stateVecInit[1]);


    /*reserve storage for states and derivatives*/

    handle->stateVec = malloc(sizeof(double) * handle->numOfStates);
    handle->derivStateVec = malloc(sizeof(double) * handle->numOfStates);

    /*init states and derivatives with zero*/

    for (int i = 0; i < handle->numOfStates; i++) {
        handle->stateVec[i] = 0;
        handle->derivStateVec[i] = 0;
    }
}

void eulerForward(simHandle *handle) { // this is called only once
    int numOfStates = handle->numOfStates;
    int integratorSteps = (int) ceil(handle->simTime / handle->stepSize); //steps bsp. 50s/0.2=250 steps
    FILE *filePointer = fopen("eulerResults.txt", "w");

    if (filePointer == NULL) {
        printf("Error opening file!\n");
        return;
    }

    /*write init states*/
    for (int i = 0; i < numOfStates; i++) {
        handle->stateVec[i] = handle->stateVecInit[i]; //gives stateVec stateVecInit values
    }
    for (int i = 0; i <= integratorSteps; i++) {
        /*get derivatives*/
        handle->f(handle->derivStateVec, handle->stateVec);
        fprintf(filePointer, "%lf ", i * handle->stepSize);

        for (int j = 0; j < numOfStates; j++) {
            /*euler step*/
            handle->stateVec[j] += handle->stepSize * handle->derivStateVec[j];
            fprintf(filePointer, "%lf ", handle->stateVec[j]);
        }
        fprintf(filePointer, "\n");
    }
    fclose(filePointer);
}

void showResultsMSD(simHandle *handle) {


/*call gnuplot*/
    FILE *gnuPlotPointer = popen("gnuplot -persistent", "w");
    fprintf(gnuPlotPointer, "plot 'eulerResults.txt' using 1:2 with lines, 'eulerResults.txt' using 1:3 with lines\n");
    pclose(gnuPlotPointer);
}
