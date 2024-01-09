#include <stdio.h>
// just skip printing the second consecutive blank character found 
int main()
{

    int c, lastc;
    lastc = EOF;
    while ((c = getchar()) != EOF){
   	 if (c == ' ') {
   		 if (lastc != ' '){
   			 putchar(c);
		 }
    }else
   	 putchar(c);
     lastc = c;
    }

    return 0;
} 
