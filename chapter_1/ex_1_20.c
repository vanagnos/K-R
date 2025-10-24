#include <stdio.h>


void detab(char *s, int tab_stop);

int main(){
    int tab_stop = 8; 
    char input[1000];

    
    printf("Enter text (Ctrl+D to end): ");
    fgets(input, sizeof(input), stdin); 

    
    detab(input, tab_stop);

    return 0;
}

void detab(char *s, int tab_stop){
    char *ptr = s;
    int current_column = 0;


    while (*ptr != '\0'){
        if (*ptr == '\t'){
            putchar(' ');
            int spaces_needed = tab_stop - (current_column % tab_stop);
            for (int i = 0; i < spaces_needed; i++) {
                putchar(' ');  
                current_column++; 
            }
        }
        else{
            putchar(*ptr);
            current_column++;
        }
        ptr++;
    }
}
