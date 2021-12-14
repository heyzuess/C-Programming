#include <stdio.h>

/* count digits, white space, others */
void main() {
    int iChar, iWhite, iOther;
    int iDigit[10];

    iWhite = iOther = 0;
    for (int i = 0; i < 10; i++) {
        iDigit[i] = 0;
    }

    printf("Please enter some text\n");

    while ((iChar = getchar()) != EOF) {
        if (iChar >= '0' && iChar <= '9') {
            iDigit[iChar - '0']++;
        } else
        if (iChar == ' '  || 
            iChar == '\n' || 
            iChar == '\t') {
            iWhite++;
        } else {
            iOther++;
        }
    }

    printf("\n\nDigits:\n");
    for (int i = 0; i < 10; i++) {
        printf("[ %d ]\t", i);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("    %d\t", iDigit[i]);
    }

    printf("\nSpaces: %d\n", iWhite);
    printf("Other: %d\n", iOther);
}