 #include <stdio.h>
 /* count newlines, tabs and blanks in input */
int main(){
    int c; 
    int nl = 0, tb = 0 , bl = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n'){
           ++nl;
        }
        else if (c == '\t'){
           ++tb;
        }
        else if (c == ' ' ){
           ++bl;
        }
    } 
    printf("New lines: %d\n", nl);
    printf("Tabs: %d\n", tb);
    printf("Blanks: %d\n", bl);


 } 
