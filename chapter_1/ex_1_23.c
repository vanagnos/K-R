#include <stdio.h>

void remove_comments(char *line);  

int main() {
    char input[1000];  

    while (fgets(input, sizeof(input), stdin) != NULL) {
        remove_comments(input);  
    }

    return 0;
}

void remove_comments(char *line) {
    char *ptr = line;   
    char *start_ptr;     
    int in_single_line_comment = 0;  
    int in_multi_line_comment = 0;   
    int in_string = 0;   
    int in_char_constant = 0;  

    while (*ptr != '\0') {  
        if (!in_single_line_comment && !in_multi_line_comment && !in_string && !in_char_constant) {
            if (*ptr == '/' && *(ptr + 1) == '/') {
                in_single_line_comment = 1;  
                ptr++;  
            }
            else if (*ptr == '/' && *(ptr + 1) == '*') {
                in_multi_line_comment = 1;  
                ptr++;  
            }
            
            else if (*ptr == '"') {
                in_string = 1;  
                ptr++;  
            }
            
            else if (*ptr == '\'') {
                in_char_constant = 1;  
                ptr++;  
            }
            else {
                putchar(*ptr);
            }
        }
        
        if (in_single_line_comment) {
            if (*ptr == '\n') {
                in_single_line_comment = 0;  
                putchar(*ptr);  
            }
        }

        if (in_multi_line_comment) {
            if (*ptr == '*' && *(ptr + 1) == '/'){
                in_multi_line_comment = 0;  
                ptr++;  
            }
        }

        if (in_string) {
            if (*ptr == '"') {
                in_string = 0;  
            }
        }

        if (in_char_constant) {
            if (*ptr == '\'') {
                in_char_constant = 0;  
            }
        }

        ptr++; 
    }
}
