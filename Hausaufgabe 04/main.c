#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "eulerLib.h"

int main() {
    simHandle myHandle;
    simHandle *handle = &myHandle;
    eulerSettingsMSD(handle);
    eulerForward(handle);
    showResultsMSD(handle);

    return 0;
}