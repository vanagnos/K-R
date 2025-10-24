#include <stdio.h>

void reverse(char *s);
int read_line(char *line, int max_length);
int main(){
    char line [1000];

    while (1){
        read_line(line, sizeof(line));
        reverse(line);
        printf("reversed: %s\n", line);
    }
    return 0;
}

void reverse(char *s){
    char *start = s; 
    char *end = s;

    while (*end != '\0'){
       end++;
    }
    end--;

    while (start < end){
       char temp = *end;
       *end = *start;
       *start = temp;

       start++;
       end--;
    }
}

int read_line(char *line, int max_length){
    int i = 0;
    char c;

    while ((i < max_length -1) && ((c = getchar()) != EOF) && (c != '\n')){
        line[i++] = c;
    }
    line[i] = '\0';
}
