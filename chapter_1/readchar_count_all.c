#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t char_count;
    size_t line_count;
    size_t tab_count;
} Count;

Count* new_count() {
    Count* count = (Count*)malloc(sizeof(Count));
    count->char_count = 0;
    count->line_count = 0;
    count->tab_count = 0;
}

void clear_count(Count* count) {
    free(count);
}

/* count lines in input */
void main() {
    int c;

    printf("Please enter some text below (Ctrl+C to exit):\n");

    Count* count = new_count();

    while ((c = getchar()) != EOF) {
        if (c == '\n') 
        {
            count->line_count++;
        } else if (c == '\t') 
        {
            count->tab_count++;
        } else
        {
            count->char_count++;
        }
    }

    printf("Line Count:\t%d\n", count->line_count);
    printf(" Tab Count:\t%d\n", count->tab_count);
    printf("Word Count:\t%d\n", count->char_count);

    clear_count(count);

    exit(EXIT_SUCCESS);
}