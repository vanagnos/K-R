#include <stdio.h>

#define MAXLINE 1000  

void fold_line(char *line, int max_col);  

int main() {
    char input[MAXLINE];  

    printf("Enter text (Ctrl+D to end):\n");
    while (fgets(input, sizeof(input), stdin) != NULL) {
        fold_line(input, 80);  
    }

    return 0;
}

void fold_line(char *line, int max_col) {
    char *ptr = line;         
    char *last_blank = NULL;   
    int current_column = 0;    

    while (*ptr != '\0') {  
        if (*ptr == ' ' || *ptr == '\t') {
            last_blank = ptr;  
        }

        if (current_column == max_col) {
            if (last_blank != NULL) {
                ptr = last_blank;  
                putchar('\n');      
                current_column = 0; 
                last_blank = NULL;  
            } else {
                putchar(*ptr);     
                putchar('\n');      
                current_column = 0; 
            }
        } else {
            putchar(*ptr);
            current_column++;
        }

        ptr++; 
    }

    if (current_column > 0) {
        putchar('\n');
    }
}

