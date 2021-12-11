#include <stdio.h>
#include <stdlib.h>

#define BLANK 0
#define NOT_BLANK 1

/* count lines in input */
void main() {
    int c;
    int state = NOT_BLANK;

    printf("Please enter some text below (Ctrl+C to exit):\n");

    while ((c = getchar()) != EOF) {
        if (c == ' ' && state == NOT_BLANK)
        {
            state = BLANK;
        } else
        if (c == ' ' && state == BLANK) {
            continue;
        } else {
            state = NOT_BLANK;
        }

        putchar(c);
    }

    exit(EXIT_SUCCESS);
}