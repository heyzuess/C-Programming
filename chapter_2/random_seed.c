#include <stdio.h>
#include <stdbool.h>

int getNumber();
int rand();
void srand(unsigned int seed);

unsigned long int next = 1;

void main() {
    int iSeed;
    int iReturn = 0;

    while ((iSeed = getNumber()) != EOF) {
        srand(iSeed);
        iReturn = rand();

        printf("\n  Seed:%d", iSeed);
        printf("\nRandom:%d\n", iReturn);
    }
}

int getNumber() {
    int iReturn = 0;
    int iNumVals = 0;

    while (true) {
        printf("\nPlease enter a number:\n");
        
        iNumVals = scanf(" %d", &iReturn);
        if (iNumVals == 0) {
            printf("Value entered is not a number\n");
            getchar();
            continue;
        }
        break;
    }

    return iReturn;   
}

/* rand: return pseudo-random integer on 0..32767 */
int rand() {
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed) {
    next = seed;
}