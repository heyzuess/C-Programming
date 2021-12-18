#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000
#define DEBUG    0

int getInput(char cString[]);
int getIntVal(char c);
void clearString(char cString[]);
int htoi(char cString[]);

void main() {
    char cInput[MAX_SIZE];
    int iSize = 0;
    int iValue = 0;

    while (true) {
        printf("\nPlease input a hex value:\n\n");

        iSize = getInput(cInput);
        iValue = htoi(cInput);

        printf("\nValue: %d\n", iValue);

        clearString(cInput);
    }
}

int htoi(char cString[]) {
    char cTemp[MAX_SIZE];
    int iPos, iTemp, iReturn;
    iPos = iTemp = iReturn = 0;

    // Check if 0x 0X prefix is used for hex value
    for (int i = 0; cString[i] != '\0'; i++) {
        if (cString[i] == 'x' || cString[i] == 'X') iPos = i + 1;
    }

    // Strip it out so we can calculate remaining digits
    if (iPos > 0) {
        for (int i = iPos; cString[i] != '\0'; i++) {
            cTemp[iTemp] = cString[i];
            iTemp++;
        }
        cTemp[iTemp] = '\0';
        iTemp++;

        clearString(cString);

        for (int i = 0; i < iTemp; i++) {
            cString[i] = cTemp[i];
        }
    }

    // from right to left, multiply digit by 16 to the nth power
    // where n is equal to the index of the digit while reading from
    // right to left
    iPos = iTemp = 0;
    for (int i = strlen(cString); i >= 0; i--) {

        if (cString[i] == '\0') continue;

        if (DEBUG) {
            printf("char: %c\n", cString[i]);
            printf(" pos: %d\n", iPos);
        }

        iTemp = getIntVal(cString[i]);

        if (DEBUG)
        printf(" val: %d\n\n", iTemp);

        iTemp = iTemp * pow(16, iPos);
        iReturn += iTemp;
        iPos++;
    }

    return iReturn;
}

int getInput(char cString[]) {
    int iSize = 0;
    int iChar;

    while ((iChar = getchar()) != EOF &&
           iChar != '\n' &&
           iChar != '\t' &&
           iChar != ' ') {

        cString[iSize] = (char)iChar;
        iSize++;
    }

    if (iSize > 0) {
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

int getIntVal(char c) {
    int iReturn = 0;
    if (c >= 'A' && c <= 'F') {
        iReturn = c - 'A' + 10;
    } else
    if (c >= 'a' && c <= 'f') {
        iReturn = c - 'a' + 10;
    } else
    if (c >= '0' && c <= '9') {
        iReturn = c - '0';
    }

    return iReturn;
}