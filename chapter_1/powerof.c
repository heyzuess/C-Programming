#include <stdio.h>
#include <stdbool.h>

#define INPUT_SIZE 255

void getNums (int* iNum, int* iPower);
void getNum (int* iPower);
size_t power(int iNum, int iPower);

/* test power function */
void main() 
{
    int iNum, iPower;

    getNum(&iPower);
    printf("\nNumber\tPower\tResult\n");
    printf("------\t-----\t------\n");
    for (int i = 0; i < 10; i++) 
    {
        printf("%d\t%d\t%d\n", i, iPower, power(i, iPower));
    }

    getNums(&iNum, &iPower);
    printf("\nNumber\tPower\tResult\n");
    printf("------\t-----\t------\n");
    printf("%d\t%d\t%d\n", iNum, iPower, power(iNum, iPower));
}

size_t power(int iNum, int iPower) {
    size_t iReturn = 1;
    for (int i = 1; i <= iPower; i++) {
        iReturn = iReturn * iNum;
    }
    return iReturn;
}

void getNum(int* iPower)
{
    size_t iNumInputs = 0;

    while (true) 
    {
        printf("\n\nPlease enter a number (to print exponent table)\n\n");
        iNumInputs = scanf("%d", iPower);

        if (iNumInputs != 1) 
        {
            iNumInputs = 0;
            continue;
        }

        break;
    }
}

void getNums (int* iNum, int* iPower) 
{
    size_t iNumInputs = 0;

    while (true) {
        printf("\n\nPlease enter two numbers (x to the power of y)\n\n");
        iNumInputs = scanf("%d %d", iNum, iPower);

        if (iNumInputs != 2) 
        {
            iNumInputs = 0;
            continue;
        }

        break;
    }
}