#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_TAB_STOP 8

void detab(int *tab_stops, int num_tabs) {
    int c;
    int column = 0;
    int tab_index = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            while (tab_index < num_tabs && tab_stops[tab_index] <= column) {
                tab_index++;
            }

            if (tab_index < num_tabs) {
                int spaces = tab_stops[tab_index] - column;
                for (int i = 0; i < spaces; i++) {
                    putchar(' ');
                }
                column += spaces;
            }
        } else {
            putchar(c);
            column++;
            if (c == '\n') {
                column = 0;
                tab_index = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int *tab_stops;
    int num_tabs = 0;

    if (argc == 1) {
        tab_stops = (int *)malloc(sizeof(int));
        tab_stops[0] = DEFAULT_TAB_STOP;
        num_tabs = 1;
    } else {
        tab_stops = (int *)malloc((argc - 1) * sizeof(int));

        for (int i = 1; i < argc; i++) {
            tab_stops[i - 1] = atoi(argv[i]);
        }
        num_tabs = argc - 1;
    }

    detab(tab_stops, num_tabs);

    free(tab_stops);

    return 0;
}
