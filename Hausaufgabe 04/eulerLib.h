#ifndef EULERLIB_H_
#define EULERLIB_H_

struct SimHandle {
    void (*f)(double *, double *);

    double *stateVec;
    double *stateVecInit;
    double *derivStateVec;
    int numOfStates;
    double stepSize;
    double simTime;
};

typedef struct SimHandle simHandle;

void errorHandlingInput (simHandle *handle);

void rhsMSD(double *, double *);

void eulerForward(simHandle *);

void showResultsMSD();

void eulerSettingsMSD(simHandle *);

#endif