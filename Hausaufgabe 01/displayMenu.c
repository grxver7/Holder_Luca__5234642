#include "complexNumberStructure.h"
#include <stdio.h>
#include <math.h>

void displayMenu(complexNumber first_Number, complexNumber second_Number, complexNumber result, char selectedMenu, char operation)
{
    double r;
    r = result.real*result.real+result.imaginary*result.imaginary;
    r = sqrt(r);
    double phi;

    //cartesian
    if (selectedMenu == 'a') {
        printf("\nResult: z=(%f%+fi)%c(%f%+fi)=%f%+fi", first_Number.real, first_Number.imaginary, operation, second_Number.real,
               second_Number.imaginary, result.real, result.imaginary);
    }
    if (result.real == 0){
        printf("\nAttention, you divided through 0!!");
    }
    else {
        phi = atan(result.imaginary/result.real);

        //polar1
        if (selectedMenu == 'b') {
            printf("\nResult: z=(%f%+fi)%c(%f%+fi)=%f*e^(%f*i)",first_Number.real, first_Number.imaginary, operation, second_Number.real,
                   second_Number.imaginary,  r, phi);
        }
        //polar2
        if (selectedMenu == 'c') {
            printf("\nResult: z=(%f%+fi)%c(%f%+fi)=%f*(cos(%f)+i*(sin(%f)",first_Number.real, first_Number.imaginary, operation,second_Number.real,
                   second_Number.imaginary, r, phi, phi);
    }
    }
}
