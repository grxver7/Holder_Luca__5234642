#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complexNumberStructure.h"

double *  stringCutter (char number[]){
    double imaginaryNumber;
    double realNumber;
    char *token;
    char *token2;
    char **ptr;
    double *numberReturn =malloc(sizeof (double) *2);

    token = strtok(number, "+"); //Teil vor plus speichern
    realNumber = strtod(token, &ptr); //zu double casten
    numberReturn[0] = realNumber; //in Rückgabeearray speichern, Speicher [0] = reele Zahl

    token = strtok(NULL, "+"); //Teil hinter plus speichern
    //printf("%s\n", token);
    token2 = strtok(token, "i"); //i entfernen
    //printf("%s\n", token2);
    imaginaryNumber= strtod(token2, &ptr);
    numberReturn[1] = imaginaryNumber; //Speicher [0] = imaginäre Zahl
    //printf("%f %f\n", numberReturn[0], numberReturn[1]);


    complexNumber secondNumber;

    return numberReturn;
}
