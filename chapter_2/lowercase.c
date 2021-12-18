#include <stdio.h>
#include <stdbool.h>

#define MAX_INPUT 1000
#define NO_INPUT  0

int getInput(char cString[]);
void clearString(char cString[]);
void toLower(char cString[]);
int lower(int c);

void main() {
    char cString[MAX_INPUT];
    int iReturn;

    while ((iReturn = getInput(cString)) != NO_INPUT) {
        toLower(cString);
        printf("\nLower Case:\n%s\n", cString);
        clearString(cString);
    }
}

int getInput(char cString[]) {
    int iSize = NO_INPUT;
    int iChar;

    printf("\nPlease enter some text:\n\n");

    while ((iChar = getchar()) != EOF &&
           iChar != '\n'              &&
           iChar != '\t') {
        cString[iSize] = (char)iChar;
        iSize++;
    }

    if (iSize > NO_INPUT) {
        cString[iSize] = '\0';
        iSize++;
    }
    
    return iSize;
}

void clearString(char cString[]) {
    for (int i = 0; cString[i] != '\0'; i++) {
        cString[i] = '\0';
    }
}

void toLower(char cString[]) {
    int iTemp = 0;
    for (int i = 0; cString[i] != '\0'; i++) {
        iTemp = lower(cString[i]);

        if (iTemp > 0) cString[i] = (char)iTemp;
    }
}

int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    } else {
        return c;
    }
}