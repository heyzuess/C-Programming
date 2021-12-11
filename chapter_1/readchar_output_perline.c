#include <stdio.h>
#include <string.h>

#define SPACE    1
#define NO_SPACE 0

void main() {
    char string[100];
    int state = NO_SPACE;
    int input;

    input = getchar();
    while (input != EOF && input != '\n') {
        if (input == ' ' && state != SPACE) {
            state = SPACE;
            input = '\n';
        } else
        if (input == ' ' && state == NO_SPACE) {
            continue;
        } else {
            state = NO_SPACE;
        }
        
        char temp = (char)input;
        strncat(string, &temp, 1);
        input = getchar();
    }

    printf("\nOutput:\n%s\n", string);
}