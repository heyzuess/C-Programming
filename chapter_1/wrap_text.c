#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 1000
#define NO_SPACE 0
#define SPACE    1

int getData(char cCollection[MAXSIZE][MAXSIZE]);

void addCollection(char cCollection[MAXSIZE][MAXSIZE], int* iCollectionSize,
                   char cString[], int* iStringSize);

void addChar(char cString[], int iStringSize, char cVal);
void clearString(char cString[], int* iStringSize);

void main()
{
    char cCollection[MAXSIZE][MAXSIZE];
    int iCollectionSize;

    printf("Please enter some text:\n\n");

    iCollectionSize = getData(cCollection);
    printf("\nPrinting string collection:\n\n");
    for (int i = 0; i < iCollectionSize; i++)
    {
        printf("String:\t%d\n", i);
        for (int j = 0; j < MAXSIZE && cCollection[i][j] != '\0'; j++) {
            printf("%c", cCollection[i][j]);
        }
        printf("\n");
    }
}

int getData(char cCollection[MAXSIZE][MAXSIZE])
{
    int iChar;
    int iState;
    int iCollectionSize = 0;
    int iStringSize = 0;
    char cString[MAXSIZE];

    for (int i = 0; i < MAXSIZE; i++) {
        cString[i] = '\0';
    }

    while ((iChar = getchar()) != EOF) {
        if ((iChar == ' '  ||
             iChar == '\n' ||
             iChar == '\t') && iState == NO_SPACE)
        {
            iState = SPACE;

            printf("closing string\n");
            addChar(cString, iStringSize, '\0');
            iStringSize++;
            /*
            cString[iStringSize] = '\0';
            iStringSize++;
            */

            printf("String: %s\n", cString);
            printf("String Length:%d\n", iStringSize);

            //addCollection(cCollection, &iCollectionSize, cString, &iStringSize);
            for (int i = 0; i < iStringSize; i++)
            {
                cCollection[iCollectionSize][i] = cString[i];
                if (cString[i] == '\0') break;
            }
            iCollectionSize++;

            //clearString(cString, &iStringSize);
            for (int i = 0; i < iStringSize; i++) {
                cString[i] = '\0';
            }
            iStringSize = 0;

            //printf("String Count:%d\n", iCollectionSize);
        } else
        if ((iChar == ' '  ||
             iChar == '\n' ||
             iChar == '\t') && iState == SPACE)
        {
            continue;
        } else
        {
            iState = NO_SPACE;

            printf("adding char %c\n", iChar);
            char cTemp = (char)iChar;
            addChar(cString, iStringSize, cTemp);
            iStringSize++;

            /*
            cString[iStringSize] = iChar;
            iStringSize++;
            */

            printf("String: %s\n", cString);
            printf("String Length:%d\n", iStringSize);
        }
    }

/*
    printf("\nPrinting string collection:\n\n");
    for (int i = 0; i < iCollectionSize; i++)
    {
        printf("String:\t%d\n", i);
        for (int j = 0; j < MAXSIZE && cCollection[i][j] != '\0'; j++) {
            printf("%c", cCollection[i][j]);
        }
        printf("\n");
    }
*/

    return iCollectionSize;
}

void addCollection(char cCollection[MAXSIZE][MAXSIZE],
                   int* iCollectionSize,
                   char cString[],
                   int* iStringSize)
{
    for (int i = 0; i < *iStringSize; i++)
    {
        cCollection[*iCollectionSize][i] = cString[i];
        if (cString[i] == '\0') break;
    }

    *iCollectionSize++;
    clearString(cString, iStringSize);
}

void addChar(char cString[], int iStringSize, char cVal)
{
    cString[iStringSize] = cVal;
}

void clearString(char cString[], int* iStringSize)
{
    for (int i = 0; i < *iStringSize; i++)
    {
        cString[i] = '\0';
    }

    *iStringSize = 0;
}