#include <math.h>
#include "functionF.h"

double functionF (double x) {
    double value;
    value = x-3;
    value = pow(value, 2);
    return value;
}

double derivationFunctionAnalytic (double x) {
    double value;
    value = x-3;
    value *= 2;
    return value;
}

double derivationFunctionNumeric (double x) {
    double value;
    double h = pow(10, -8);
    double (*getFunction)(double) = &functionF;
    value = (*getFunction)(x+h)-(*getFunction)(x);
    value = value/h;
    return value;
}
