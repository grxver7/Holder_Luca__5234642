#include <stdio.h>
#include <math.h>
#include "complexNumberStructure.h"

double operation (complexNumber first_Number, complexNumber second_Number) {
    double result_realNumber;
    double result_imaginaryNumber;

    // z1 = a + bi, z2 = c + di
    // addition z1 + z2 = (a+c) + i(b+d)
    result_realNumber = first_Number.real + second_Number.real;
    result_imaginaryNumber =+ first_Number.imaginary + second_Number.imaginary;

    printf("\nAddition: \n (%f+%fi)+(%f+%fi)=%f+%fi \n", first_Number.real, first_Number.imaginary, second_Number.real,
           second_Number.imaginary, result_realNumber, result_imaginaryNumber);
    //printf("%f+%f i \n", &result_realNumber, &result_imaginaryNumber);

    // subtraction z1 - z2 = (a-c) + i(b-d)
    result_realNumber = first_Number.real - second_Number.real;
    result_imaginaryNumber =+ first_Number.imaginary - second_Number.imaginary;

    printf("Subtraction: \n(%f-%fi)+(%f-%fi)=%f+%fi \n", first_Number.real, first_Number.imaginary, second_Number.real,
           second_Number.imaginary, result_realNumber, result_imaginaryNumber);

    // multiplication z1 · z2 = (ac - bd) + i(ad + bc)
    result_realNumber = (first_Number.real * second_Number.real)-(first_Number.imaginary*second_Number.imaginary);
    result_imaginaryNumber = (first_Number.real * second_Number.imaginary)+(first_Number.imaginary*second_Number.real);

    printf("Multiplication: \n(%f-%fi)*(%f-%fi)=%f+%fi \n", first_Number.real, first_Number.imaginary, second_Number.real,
           second_Number.imaginary, result_realNumber, result_imaginaryNumber);

    // division z1/z2 = (ac+bd)/(c*c+d*d)+(bc-ad)/(c*c+d*d)
    result_realNumber = (first_Number.real*second_Number.real+first_Number.imaginary*second_Number.imaginary)
            /((second_Number.real*second_Number.real)+(second_Number.imaginary*second_Number.imaginary));
    result_imaginaryNumber = (first_Number.imaginary*second_Number.real-first_Number.real*second_Number.imaginary)
             /((second_Number.real*second_Number.real)+(second_Number.imaginary*second_Number.imaginary));

    if (isnan(result_imaginaryNumber)||isnan(result_realNumber)) {
        printf("Division: \nAttention, you divided through 0!!");
    }
    else {
        printf("Division: \n(%f-%fi)/(%f-%fi)=%f+%fi \n", first_Number.real, first_Number.imaginary, second_Number.real,
               second_Number.imaginary, result_realNumber, result_imaginaryNumber);
    }
}