#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 255
#define HIST_SIZE  26

// Prints the histogram
void printHistogram(int iHist[]) {

    printf("\n\nLength\tCount\n");
    printf("------\t-----\n");
    
    for (int i = 0; i < HIST_SIZE; i++) {
        char cTemp = (char)(i + 'A');
        printf("%5c:\t", cTemp);

        for (int j = 0; j < iHist[i]; j++) {
            printf("#");
        }

        printf("[%d]\n", iHist[i]);
    }
    printf("\n");
}

void main() 
{
    char cWord[INPUT_SIZE];
    int iHist[HIST_SIZE];
    int iChar;

    for (int i = 0; i < HIST_SIZE; i++) 
    {
        iHist[i] = 0;
    }

    printf("Please enter some text:\n\n");

    while ((iChar = getchar()) != EOF) 
    {
        if (iChar == ' '  ||
            iChar == '\n' ||
            iChar == '\t')
        {
            int iRange = strlen(cWord);
            for (int i = 0; i < iRange; i++)
            {
                char cDiff;
                int iDiff;
                char cTemp = cWord[i];
                int iTemp = (int)cTemp;

                if (cTemp > 'Z') {
                    cDiff = 'a';
                } else {
                    cDiff = 'A';
                }

                iDiff = (int)cDiff;
                iHist[iTemp - iDiff]++;
            }

            strcpy(cWord, "");
        } else {
            char cTemp = (char)iChar;
            strncat(cWord, &cTemp, 1);
        }
    }
    
    printHistogram(iHist);
}