#include <stdio.h>

void replace_spaces(char *s, int tab_stop);

int main(){
    int tab_stop = 8; 
    char input[1000];

    
    printf("Enter text (Ctrl+D to end): ");
    fgets(input, sizeof(input), stdin); 

    
    replace_spaces(input, tab_stop);

    return 0;
}

void replace_spaces(char *s, int tab_stop){
    char *ptr = s;
    int current_column = 0;
    int spaces = 0;

    while (*ptr != '\0'){
        if (*ptr == ' '){
            spaces++;
        } else{
         
        while (spaces > 0){
            int tabs_to_print = spaces / tab_stop;
            int remaining_spaces = spaces % tab_stop;
            for (int i = 0; i < tabs_to_print; i++) {
                    putchar('\t');
                    current_column += tab_stop;
            }
            for (int i = 0; i < remaining_spaces; i++) {
                putchar(' ');
                current_column++;
            }

            spaces = 0;
         }
         putchar(*ptr);
         current_column++;
        }
        ptr++;
    }
}
