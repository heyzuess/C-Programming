#include <stdio.h>
#define MAXLINE 1000 /* Maximum input line length */

int get_line(char cString[], int iLimit);
void copy_line(char cTo[], char cFrom[]);

/* print the longest input line */
void main()
{
    int iLength;            // Current line length
    int iMax;               // Maximum length seen so far
    char cLine[MAXLINE];    // Current input line
    char cLongest[MAXLINE]; // Longest line saved here

    printf("Please enter some text:\n\n");

    iMax = 0;
    while ((iLength = get_line(cLine, MAXLINE)) > 0)
    {
        if (iLength > iMax) 
        {
            iMax = iLength;
            copy_line(cLongest, cLine);
        }
    }

    if (iMax > 0)
    {
        printf("\n\nLongest Line:\n%s", cLongest);
    }
}

/* getline: read a line into s, return a length */
int get_line(char cString[], int iLimit)
{
    int iChar;
    int iSize;

    for (iSize = 0; iSize < iLimit - 1  && 
         (iChar = getchar()) != EOF &&
         iChar != '\n'; iSize++)
    {
        cString[iSize] = iChar;       
    }

    if (iChar == '\n')
    {
        cString[iSize] = iChar;
        iSize++;
    }

    cString[iSize] = '\0';
    return iSize;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy_line(char cTo[], char cFrom[])
{
    int i = 0;
    while ((cTo[i] = cFrom[i]) != '\0')
    {
        i++;
    }
}