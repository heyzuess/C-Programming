#include <stdio.h>
#include <stdbool.h>

#define MAX_INPUT 255
#define NO_INPUT  0
#define DEBUG     0

int atoi(char cString[]);
int getInput(char cString[]);
void clearString(char cString[]);

void main() {
    char cInput[MAX_INPUT];
    int iValue;
    int iReturn;

    while ((iReturn = getInput(cInput)) != NO_INPUT &&
           iReturn != EOF) {
        iValue = atoi(cInput);
        printf("\nValue: %d\n", iValue);
        clearString(cInput);
    }
}

int atoi(char cString[]) {
    int iReturn = 0;

    if (DEBUG)
    printf("\n<-- START DEBUG -->\n");

    for (int i = 0; cString[i] >= '0' && cString[i] <= '9'; i++) {
        iReturn = 10 * iReturn + (cString[i] - '0');

        if (DEBUG)
        printf("iReturn:%d\nCstring[%d]:%c\n", 
               iReturn, i, cString[i]);
    }

    if (DEBUG)
    printf("<-- END DEBUG -->\n");

    return iReturn;
}

void clearString(char cString[]) {
    for (int i = 0; cString[i] != '\0'; i++) {
        cString[i] = '\0';
    }
}

int getInput(char cString[]) {
    int iChar;
    int iSize = NO_INPUT;

    while (true) {
        printf("\nPlease enter a number:\n");

        while ((iChar = getchar()) != EOF &&
               iChar != '\n' &&
               iChar != '\t' &&
               iChar != ' ') {

            if (iChar >= '0' && iChar <= '9') {
                cString[iSize] = (char)iChar;
                iSize++;
            }
        }

        if (iChar == EOF && iSize <= NO_INPUT) return EOF;

        if (iSize <= NO_INPUT) {
            continue;
        }

        break;
    }

    if (iSize > NO_INPUT) {
        cString[iSize] = '\0';
        iSize++;
    }

    return iSize;
}