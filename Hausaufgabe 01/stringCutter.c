#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double *  stringCutter (char number[]){
    double imaginaryNumber;
    double realNumber;
    char *token;
    double *numberReturn =malloc(sizeof (double) *2);

    if ((strchr(number, '+') == NULL)) {
        printf("Error, invalid input!");
        return NULL;
    }

    token = strtok(number, "+"); //first part before '+'

    if (strchr(token, 'i') != NULL) { //imaginary number is first number
        imaginaryNumber = strtod(token, NULL); //cast to double
        numberReturn[1] = imaginaryNumber; //storage [1] = imaginary

        token = strtok(NULL, "+"); //part after '+'
        token = strtok(token, "i"); //cut i
        realNumber = strtod(token, NULL);
        numberReturn[0] = realNumber; //storage [0] = real
    }
    else {
        token=token;
        realNumber = strtod(token, NULL);
        numberReturn[0] = realNumber;

        token = strtok(NULL, "+");
        token = strtok(token, "i");
        imaginaryNumber= strtod(token, NULL);
        numberReturn[1] = imaginaryNumber;
    }

    return numberReturn;
}