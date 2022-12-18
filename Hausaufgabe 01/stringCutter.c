#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double *  stringCutter (char number[]){
    double imaginaryNumber;
    double realNumber;
    char *token;
    char **ptr;
    double *numberReturn =malloc(sizeof (double) *2);
    //char userCorrection;

    if ((strchr(number, '+') == NULL)) {
        printf("Error, invalid input!");
        return NULL;
    }

    //if does contain invalid inputs

    token = strtok(number, "+"); //first part before '+'

    if (strchr(token, 'i') != NULL) { //imaginary number is first number
        imaginaryNumber = strtod(token, &ptr); //cast to double
        numberReturn[1] = imaginaryNumber; //storage [1] = imaginary

        token = strtok(NULL, "+"); //part after '+'
        token = strtok(token, "i"); //cut i
        realNumber = strtod(token, &ptr);
        numberReturn[0] = realNumber; //storage [0] = real
    }
    else {
        token=token;
        realNumber = strtod(token, &ptr);
        numberReturn[0] = realNumber;

        token = strtok(NULL, "+");
        token = strtok(token, "i");
        imaginaryNumber= strtod(token, &ptr);
        numberReturn[1] = imaginaryNumber;
    }

    return numberReturn;
}