#include <stdio.h>
int main()
{
    int c, lastc;
    lastc = EOF;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (lastc != ' ') {
                putchar(c);
            }
        } else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
        lastc = c;
    }

    return 0;
}

} 

