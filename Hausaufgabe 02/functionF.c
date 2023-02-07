#include <math.h>
#include "functionF.h"
//Bibliothek Funktionen
double functionF (double x) {
    x = x-11;
    x = pow(x, 2);
    return x;
}

double derivationFunctionAnalytic (double x) {
    x = x-3;
    x *= 2;
    return x;
}

double derivationFunctionNumeric (double x) {
    double h = pow(10, -8);
    double (*getFunction)(double) = &functionF;
    x = (*getFunction)(x+h)-(*getFunction)(x);
    x = x/h;
    return x;
}
