#include <stdio.h>
#include <math.h>
#include "complexNumberStructure.h"
#include "displayMenu.h"

void operation (complexNumber first_Number, complexNumber second_Number, char selectedMenu) {
    complexNumber result;
    char operation;

    // z1 = a + bi, z2 = c + di

    // addition z1 + z2 = (a+c) + i(b+d)
    operation= '+';
    result.real = first_Number.real + second_Number.real;
    result.imaginary =+ first_Number.imaginary + second_Number.imaginary;

    printf("\nAddition: ");
    displayMenu(first_Number, second_Number, result, selectedMenu, operation);;

    // subtraction z1 - z2 = (a-c) + i(b-d)
    operation= '-';
    result.real = first_Number.real - second_Number.real;
    result.imaginary =+ first_Number.imaginary - second_Number.imaginary;

    printf("\nSubtraction:");
    displayMenu(first_Number, second_Number, result, selectedMenu, operation);;

    // multiplication z1 · z2 = (ac - bd) + i(ad + bc)
    operation='*';
    result.real = (first_Number.real * second_Number.real)-(first_Number.imaginary*second_Number.imaginary);
    result.imaginary = (first_Number.real * second_Number.imaginary)+(first_Number.imaginary*second_Number.real);

    printf("\nMultiplication: ");
    displayMenu(first_Number, second_Number, result, selectedMenu, operation);

    // division z1/z2 = (ac+bd)/(c*c+d*d)+(bc-ad)/(c*c+d*d)
    operation='/';
    result.real = (first_Number.real*second_Number.real+first_Number.imaginary*second_Number.imaginary)
            /((second_Number.real*second_Number.real)+(second_Number.imaginary*second_Number.imaginary));
    result.imaginary = (first_Number.imaginary*second_Number.real-first_Number.real*second_Number.imaginary)
             /((second_Number.real*second_Number.real)+(second_Number.imaginary*second_Number.imaginary));

    if (isnan(result.real)||isnan(result.imaginary)) {
        printf("\nDivision: \nAttention, you divided through 0!!");
    }
    else {
        printf("\nDivision: ");
        displayMenu(first_Number, second_Number, result, selectedMenu, operation);
    }
}