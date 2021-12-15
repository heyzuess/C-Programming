#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 1000

int get_line (char cString[], int iRange);
void reverse_string (char cString[], char cReverse[]);

void main()
{
    char cString[MAXSIZE];
    char cReverse[MAXSIZE];

    while (true)
    {
        printf("Please enter some text:\n");

        if (get_line(cString, MAXSIZE) == 0) break;

        reverse_string(cString, cReverse);
        printf("\nReversed String:\n%s\n\n", cReverse);
    }
}

int get_line (char cString[], int iRange) {
    int iSize;
    int iChar;

    for (int i = 0; i < iRange - 1  &&
         (iChar = getchar()) != EOF &&
         iChar != '\n'; i++)
    {
        cString[iSize] = iChar;
        iSize++;
    }

/*
    if (iChar == '\n') {
        cString[iSize] = iChar;
        iSize++;
    }
*/

    cString[iSize] = '\0';
    iSize++;

    return iSize;
}

void reverse_string(char cString[], char cReverse[])
{
    int iRange = 0;

    while (cString[iRange] != '\0') 
    {
        iRange++;
    }

    for (int i = 1; i <= iRange; i++) 
    {
        cReverse[i - 1] = cString[iRange - i];
    }

    cReverse[iRange] = '\0';
}