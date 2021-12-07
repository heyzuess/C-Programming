#include <stdio.h>

/* copy input to output; 1st version */
void main()
{
    long nc;
    
    nc = 0;

    printf("Please write some text below (Ctrl+C to complete):\n");
    printf("--------------------------------------------------\n");

    while (getchar() != EOF) ++nc;
    printf("Num Chars:\t%ld\n", nc);
}