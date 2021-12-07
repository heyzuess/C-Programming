#include <stdio.h>

/* count lines in input */
void main() {
    int c, nl;

    printf("Please enter some text below (Ctrl+C to exit):\n");

    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') ++nl;
    }

    printf("Line Count:\t%d\n", nl);
}