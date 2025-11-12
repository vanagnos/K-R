#include <stdio.h>
#include <stdlib.h>

#define MAX_STOPS 100
#define DEFAULT_STOP 8

void entab(char *s, int stops[], int n);

int main(int argc, char *argv[]) {
    int tab_stops[MAX_STOPS];
    int num_stops = 0;

    if (argc == 1) {
        printf("No arguments. Using default tab stop of %d.\n", DEFAULT_STOP);
        num_stops = 1;
        tab_stops[0] = DEFAULT_STOP;
    } else {
        printf("Using custom tab stops: ");
        for (int i = 1; i < argc && num_stops < MAX_STOPS; i++) {
            int stop = atoi(argv[i]);
            if (stop > 0) {
                tab_stops[num_stops++] = stop;
                printf("%d ", stop);
            }
        }
        printf("\n");

        if (num_stops == 0) {
            printf("Invalid arguments. Using default %d.\n", DEFAULT_STOP);
            num_stops = 1;
            tab_stops[0] = DEFAULT_STOP;
        }
    }

    char input[1000];

    printf("Enter text (Ctrl+D to end):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        entab(input, tab_stops, num_stops);
    }

    return 0;
}

void entab(char *s, int stops[], int n) {
    int column = 0;
    int space_count = 0;
    int stop_index = 0; // Tracks which custom tab stop we're aiming for

    // Check if we are using the simple default (n=1, stop=8)
    int is_default_repeating = (n == 1 && stops[0] == DEFAULT_STOP);

    for (char *ptr = s; *ptr != '\0'; ptr++) {
        if (*ptr == ' ') {
            space_count++; // Count consecutive spaces
        } else {
            // We hit a non-space. Process any pending spaces.
            while (space_count > 0) {
                int next_stop;
                
                // --- Find the next tab stop ---
                if (is_default_repeating) {
                    // Default logic: next stop is at (col/8 + 1) * 8
                    next_stop = (column / DEFAULT_STOP + 1) * DEFAULT_STOP;
                } else {
                    // Custom list logic: find the next stop > current column
                    while (stop_index < n && stops[stop_index] <= column) {
                        stop_index++;
                    }
                    if (stop_index < n) {
                        next_stop = stops[stop_index]; // Found a stop
                    } else {
                        next_stop = column + 1; // Past end of list, act as a space
                    }
                }
                // --- End find next tab stop ---

                int spaces_to_next = next_stop - column;

                // Can we use a tab?
                // Only if it's optimal (spans > 1 space) and we have enough spaces.
                if (spaces_to_next > 1 && space_count >= spaces_to_next) {
                    putchar('\t');
                    column = next_stop;
                    space_count -= spaces_to_next;
                } else {
                    // Can't use a tab. Print a single space.
                    putchar(' ');
                    column++;
                    space_count--;
                }
            } // end while (space_count > 0)

            // --- Now print the actual character that ended the space run ---
            putchar(*ptr);

            if (*ptr == '\n') {
                column = 0;       // Reset column on newline
                stop_index = 0;   // Reset tab stop list index
            } else if (*ptr == '\t') {
                // Handle tabs *in the input*
                int next_stop;
                if (is_default_repeating) {
                    next_stop = (column / DEFAULT_STOP + 1) * DEFAULT_STOP;
                } else {
                    while (stop_index < n && stops[stop_index] <= column) {
                        stop_index++;
                    }
                    if (stop_index < n) {
                        next_stop = stops[stop_index];
                    } else {
                        next_stop = column + 1;
                    }
                }
                column = next_stop; // Advance column to the next stop
            } else {
                column++; // Increment column for any other character
            }
        }
    }
}
