#include <stdio.h>

#define LOWER 0   /* lower limit of temperature scale */
#define UPPER 300 /* upper limit */
#define STEP  20  /* step size */

/* Print Fahrenheit-Celsius table */
void fahr_to_celcius()
{
    float fahr, celsius;

    fahr = LOWER;

    /* print the header column */
    printf("+-----------------------+\n");
    printf("| Fahr to Celsius Table |\n");
    printf("+-----------------------+\n");
    printf("Fahr\tCelsius\n");
    printf("----\t-------\n");

    while (fahr <= UPPER)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    printf("\n");
}

/* Print Celcius to Fahrenheit */
void celcius_to_fahr ()
{
    float fahr, celsius;

    celsius = LOWER;

    /* print the header column */
    printf("+-----------------------+\n");
    printf("| Celsius to Fahr Table |\n");
    printf("+-----------------------+\n");
    printf("Celsius\tFahr\n");
    printf("-------\t----\n");

    while (celsius <= UPPER)
    {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }

    printf("\n");
}

/* Print both tables */
void main()
{
    fahr_to_celcius();
    celcius_to_fahr();
}