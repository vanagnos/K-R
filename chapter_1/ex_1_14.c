#include <stdio.h>

#define TOTAL_CHARS 128

int main(void) {
    int c, i, j;

    int _char[TOTAL_CHARS];

    for (i = 0; i < TOTAL_CHARS; ++i) {
        _char[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if ( c < TOTAL_CHARS ) {
           ++_char[c];
        }
    }

    for (i = 0; i < TOTAL_CHARS; i++) {
        if (_char[i] > 0) {
            if (i == '\n')
                printf("\\n ");
            else if (i == '\t')
                printf("\\t ");
            else if (i == ' ')
                printf("' '");
            else
                printf(" %c ", i);

            printf(": ");
        for (j = 0; j < _char[i]; j++)
            putchar('*');

        putchar('\n');
        }
    }
    return 0;
}
