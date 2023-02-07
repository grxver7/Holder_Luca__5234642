#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

int integerScanner() {
    int inputSuccess;
    int scannerVariable;
    do {
        inputSuccess = scanf("%d", &scannerVariable);
        if (inputSuccess != 1) {
            printf("Invalid input, please retype: ");
            while (getchar() != '\n');
        }
    } while (inputSuccess != 1);
    return scannerVariable;
}

void addListElem(listElement *start) {
    listElement *new;
    new = (listElement *) malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n");
        return;
    }

    listElement *currElem = start;
    listElement *checkElem = start;
    int checkID = 0;

    while (currElem->nextElem != NULL)
        currElem = currElem->nextElem; // get last elem in list
    currElem->nextElem = new;          // add new to the end of list
    new->nextElem = NULL;

    /* fill data in new element */
    while (checkElem->nextElem != NULL) {
        if (checkID != checkElem->id) {
            new->id = checkID;
        }
        checkID++;
        checkElem = checkElem->nextElem;
    }
    printf("Please enter last name: \n");
    scanf("%s", new->lastName);
    printf("Please enter first name: \n");
    scanf("%s", new->firstName);
    printf("Please enter age: \n");
    new->age = integerScanner();
}

void printList(listElement *start) {
    if (start->nextElem == NULL) {
        printf("List is empty.\n");
        return;
    }
    int i = 0;
    listElement *currElem = start;
    printf("\ncurrent list:\n\n");
    do {
        currElem = currElem->nextElem;
        i++;
        printf("%d", currElem->id);
        printf("\t last name: %s\n", currElem->lastName);
        printf("\t first name: %s\n", currElem->firstName);
        printf("\t age: %d\n", currElem->age);
    } while (currElem->nextElem != NULL);
}

void delListElem(listElement *start) {
    printList(start);
    if (start->nextElem == NULL) {
        return;
    }
    int deleteID;
    listElement *deleteElem;
    listElement *currentElem;
    listElement *previousElem = start;

    printf("\nPlease type in the ID of the element to delete it\n");
    deleteID = integerScanner();

    do {
        currentElem = previousElem->nextElem;
        if (currentElem->id == deleteID) {
            deleteElem = currentElem;
            previousElem->nextElem = deleteElem->nextElem;
            free(deleteElem);
            printf("Delete request was successful\n\n");
            return;
        }
        previousElem = currentElem;
    } while (currentElem->nextElem != NULL);

    printf("\nSomething went wrong. Do you typed the correct ID?\n");

}

void delList(listElement *start) {
    if (start->nextElem == NULL) {
        printf("List is already empty.\n");
        return;
    }
    listElement *currentElem = start;
    listElement *deleteElem;
    do {
        deleteElem = currentElem->nextElem;
        currentElem->nextElem = deleteElem->nextElem;
        free(deleteElem);
    } while (currentElem->nextElem != NULL);
    printf("\nList successfully cleared\n");

}

int getLenOfList(listElement *start) { // we use this for save list fcn

    int counter = 0;
    listElement *currElem = start;
    while (currElem->nextElem != NULL) { // get last elem in list
        currElem = currElem->nextElem;
        counter++;
    }
    return counter;
}

void saveList(listElement *start) {
    FILE *pointerToFile;
    char filename[255];

    printf("Please name your file [format: NAME.txt]: ");
    scanf("%s", filename);

    pointerToFile = fopen(filename, "w");

    if (pointerToFile == NULL) {
        printf("\nUnable to write in file\n");
        return;
    }
    if (start->nextElem == NULL) {
        printf("\nList was empty.\n");
        return;
    }
    listElement *currentElem = start;
    do {
        currentElem = currentElem->nextElem;
        fprintf(pointerToFile, "%d", currentElem->id);
        fprintf(pointerToFile, "\t last name: %s\n", currentElem->lastName);
        fprintf(pointerToFile, "\t first name: %s\n", currentElem->firstName);
        fprintf(pointerToFile, "\t age: %d\n", currentElem->age);
    } while (currentElem->nextElem != NULL);
    printf("\nSaved\n");

    fclose(pointerToFile);
}

void loadList(listElement *start) {
    FILE *pointerToFile;
    char filename[255];

    system("dir *.txt");

    printf("\n\nAttention: \nLoading a file will reorder the IDs!\n");
    printf("\nPlease select your file by entering a name: ");
    scanf("%s", filename);

    pointerToFile = fopen(filename, "r");
    if (pointerToFile == NULL) {
        printf("\nUnable to write in file\n");
        return;
    }
    listElement *new;
    listElement *currentElem = start;
    listElement *checkElem = start;
    int checkID = 0;
    while (currentElem->nextElem != NULL)
        currentElem = currentElem->nextElem;

    while (!feof(pointerToFile)) {
        new = (listElement *) malloc(sizeof(listElement));
        if (new == NULL) {
            printf("can't reserve storage.\n");
            return;
        }
        currentElem->nextElem = new;
        new->nextElem = NULL;

        if (fscanf(pointerToFile, "%d", &(new->id)) != 1) {
            break;
        }
        while (checkElem->nextElem != NULL) {
            if (checkID != checkElem->id) {
                new->id = checkID;
            }
            checkID++;
            checkElem = checkElem->nextElem;
        }
        fscanf(pointerToFile, "\t last name: %s\n", new->lastName);
        fscanf(pointerToFile, "\t first name: %s\n", new->firstName);
        fscanf(pointerToFile, "\t age: %d\n", &(new->age));
        currentElem = new;
    }
    fclose(pointerToFile);
}

void exitFcn(listElement *start) {
    int userInquiry;
    if (start->nextElem != NULL) {
        printf("\nSave your program: [1]yes: ");
        scanf("%d", &userInquiry);
        if (userInquiry == 1)
            saveList(start);
    }
    delList(start);
    printf("\nHave a nice day ;)");
}

void sortList(listElement *start) {
/*    listElement *followingElement;
    listElement *previousElement = start;
    listElement *currentElem;
    int checkSortList = 1;

    if (start->nextElem == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (checkSortList != 0) {
        checkSortList = 0;
        currentElem = start->nextElem;
        while (currentElem->nextElem != NULL) {
            followingElement = currentElem->nextElem;
            if (currentElem->age > followingElement->age) {
                previousElement->nextElem = currentElem->nextElem;
                currentElem->nextElem = followingElement->nextElem;
                followingElement->nextElem = currentElem;
                checkSortList = 1;
            } else {
                currentElem = currentElem->nextElem;
                previousElement = previousElement->nextElem;
            }
        }
    }
    printf("\nList sorted\n");
}
*/
void stringToLower(char *string) {

    printf("\n>>stringToLower fcn is tbd.\n\n");
}
