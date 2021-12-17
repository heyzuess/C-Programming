#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 1000
#define DEBUG 0

#define NO_SPACE 0
#define SPACE    1

int getScreenWidth();
int getData(char cCollection[MAXSIZE][MAXSIZE]);

void addCollection(char cCollection[MAXSIZE][MAXSIZE], int *iCollectionSize,
                   char cString[], int *iStringSize);

void addChar(char cString[], int *iStringSize, char cVal);
void clearString(char cString[], int* iStringSize);
int stringLength (char cString[]);

void main()
{
    char cCollection[MAXSIZE][MAXSIZE];
    int iCollectionSize;
    int iScreenWidth;

    printf("Please enter screen width:\n\n");
    iScreenWidth = getScreenWidth();

    printf("\nScreen width: %d\n\n", iScreenWidth);

    printf("Please enter some text:\n\n");
    iCollectionSize = getData(cCollection);

    if (DEBUG)
    {
        printf("\nPrinting string collection:\n\n");
        for (int i = 0; i < iCollectionSize; i++)
        {
            printf("String:\t%d\n", i + 1);
            for (int j = 0; j < MAXSIZE && cCollection[i][j] != '\0'; j++) {
                printf("%c", cCollection[i][j]);
            }
            printf("\n");
        }
    }

    printf("\nWrapped Text:\n\n");
    int iCurrLength = 0;
    for (int i = 0; i < iCollectionSize; i++) {
        // Here *cString is a pointer to the string array in the collection
        // we are adding i to scale the y index of the two dimensional array
        // and casting it to a pointer so we can deference it as a string
        char *cString = *(cCollection + i);
        int iLength = stringLength(cString);

        if (iLength + iCurrLength > iScreenWidth) {
            printf("\n");
            iCurrLength = 0;
        }

        printf("%s", cString);
        iCurrLength += iLength;

        if (i + 1 < iCollectionSize &&
            iCurrLength + 1 <= iScreenWidth) {
            printf(" ");
            iCurrLength++;
        }
    }
    printf("\n");
}

int getScreenWidth()
{
    int iChar;
    int iReturn = 0;
    int iDefault = 10;

    while ((iChar = getchar()) != EOF)
    {
        if (iChar >= '0' && iChar <= '9') iReturn = 10 * iReturn + (iChar - '0');
        if (iChar == '\n' || iChar == '\t') break;
    }
    if (iReturn <= 0) iReturn = iDefault;
    return iReturn;
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

            if (DEBUG) printf("closing string\n");
            addChar(cString, &iStringSize, '\0');

            if (DEBUG)
            {
                printf("String: %s\n", cString);
                printf("String Length:%d\n", iStringSize);
            }

            addCollection(cCollection, &iCollectionSize, cString, &iStringSize);
            clearString(cString, &iStringSize);

            if (DEBUG) printf("String Count:%d\n", iCollectionSize);
        } else
        if ((iChar == ' '  ||
             iChar == '\n' ||
             iChar == '\t') && iState == SPACE)
        {
            continue;
        } else
        {
            iState = NO_SPACE;

            if (DEBUG) printf("adding char %c\n", iChar);

            char cTemp = (char)iChar;
            addChar(cString, &iStringSize, cTemp);

            if (DEBUG)
            {
                printf("String: %s\n", cString);
                printf("String Length:%d\n", iStringSize);
            }
        }
    }

    return iCollectionSize;
}

void addCollection(char cCollection[MAXSIZE][MAXSIZE],
                   int *iCollectionSize,
                   char cString[],
                   int *iStringSize)
{
    for (int i = 0; i < *iStringSize; i++)
    {
        cCollection[*iCollectionSize][i] = cString[i];
        if (cString[i] == '\0') break;
    }

    (*iCollectionSize)++;
}

void addChar(char cString[], int *iStringSize, char cVal)
{
    cString[*iStringSize] = cVal;
    (*iStringSize)++;
}

void clearString(char cString[], int* iStringSize)
{
    for (int i = 0; i < *iStringSize; i++)
    {
        cString[i] = '\0';
    }

    *iStringSize = 0;
}

int stringLength(char cString[])
{
    int iReturn;
    for (iReturn = 0; cString[iReturn] != '\0'; iReturn++);
    return iReturn;
}