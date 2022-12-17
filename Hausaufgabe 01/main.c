#include <stdio.h>
#include "operation.h"
#include "stringCutter.h"
#include "complexNumberStructure.h"
#import <malloc.h>

int main() {
    double result;
    char first_cNumber[500];
    char second_cNumber[500];
    double *number1;
    double *number2;

    printf("Please type your first number: ");
    scanf("%s", first_cNumber);
    printf("Please type your second number: ");
    scanf("%s", second_cNumber);

    number1 = stringCutter(first_cNumber);
    number2 = stringCutter(second_cNumber);

    complexNumber first_Number;
    first_Number.real= *(number1 + 0);
    first_Number.imaginary= *(number1 + 1);

    complexNumber second_Number;
    second_Number.real= *(number2 + 0);
    second_Number.imaginary= *(number2 + 1);

    /*printf("%f\n", *(number1 + 0));
    printf("%f\n", *(number1 + 1));*/

    operation(first_Number, second_Number);
    free (number1);
    free (number2);
    //return 0;
}