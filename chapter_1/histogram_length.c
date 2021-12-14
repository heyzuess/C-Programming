#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 255

// Prints the histogram
void printHistogram(int iHist[]) {

    printf("\n\nLength\tCount\n");
    printf("------\t-----\n");
    
    for (int i = 0; i < INPUT_SIZE; i++) {
        
        if (iHist[i] <= 0) {
            continue;
        }

        printf("%5d:\t", i);

        for (int j = 0; j < iHist[i]; j++) {
            printf("#");
        }

        printf("[%d]\n", iHist[i]);
    }
    printf("\n");
}

void main() {
    char cWord[INPUT_SIZE];
    int iHist[INPUT_SIZE];
    int iChar;

    for (int i = 0; i < INPUT_SIZE; i++) {
        iHist[i] = 0;
    }

    printf("Please enter some text:\n\n");

    while ((iChar = getchar()) != EOF) {
        if (iChar == ' '  || 
            iChar == '\n' || 
            iChar == '\t') {
            int iLength = strlen(cWord);

            if (iLength > 0) {
                iHist[strlen(cWord)]++;
                strcpy(cWord, "");
            }
        } else {
            char cTemp = (char)iChar;
            strncat(cWord, &cTemp, 1);
        }
    }

    printHistogram(iHist);
}