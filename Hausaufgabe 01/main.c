#include <stdio.h>
#include <malloc.h>
#include "operation.h"
#include "stringCutter.h"
#include "complexNumberStructure.h"

int main() {
    char first_cNumber[500];
    char second_cNumber[500];
    double *number1;
    double *number2;
    char selectedMenu;

    //number1
    printf("Please type your first number: ");
    scanf("%s", first_cNumber);
    number1 = stringCutter(first_cNumber);
    if (number1 == NULL) {
        exit(-1);
    }

    //number2
    printf("Please type your second number: ");
    scanf("%s", second_cNumber);
    number2 = stringCutter(second_cNumber);
    if (number2 == NULL) {
        exit(-1);
    }

    //operation
    printf("Please select your output: \ncartesian: a\npolar1 b\npolar 2: c");
    printf("\nInput: ");
    scanf("\n%c", &selectedMenu);
    if (selectedMenu != 'a'&& selectedMenu !='b' && selectedMenu !='c') {
        printf("Invalid character");
        exit(0);
    }

    complexNumber first_Number;
    first_Number.real = *(number1 + 0);
    first_Number.imaginary = *(number1 + 1);
    complexNumber second_Number;
    second_Number.real = *(number2 + 0);
    second_Number.imaginary = *(number2 + 1);

    operation(first_Number, second_Number, selectedMenu);
    free(number1);
    free(number2);
}