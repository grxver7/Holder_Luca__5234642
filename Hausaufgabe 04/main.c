#include "eulerLib.h"

int main() {
    simHandle myHandle;
    simHandle *handle = &myHandle;
    eulerSettingsMSD(handle);
    eulerForward(handle);
    showResultsMSD();

    return 0;
}