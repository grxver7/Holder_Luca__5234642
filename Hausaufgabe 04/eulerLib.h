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

/**
    \FUNCTION: RHS_MSD

    \DESCRIPTION: right-hand-side of mass spring damper system

    \param[in]  reference to current state vector for 2D first oder ode

    \param[in]  reference to storage vector for derivatives [out]
*/
void rhsMSD(double *, double *);

/**
    \DATE: 2021-01-10

    \DESCRIPTION: explicit euler function to solve first order ode-system

    \param[in]  reference to simHandle

*/
void eulerForward(simHandle *);

/**
    \DESCRIPTION: visualize the results of given ode-system solved by given used sim method
 
    \param[in]  reference to simHandle 

*/
void showResultsMSD(simHandle *);

/**
    \DESCRIPTION: initialize simHandle by user defined specs
 
    \param[in]  reference to simHandle 

*/
void eulerSettingsMSD(simHandle *);

#endif