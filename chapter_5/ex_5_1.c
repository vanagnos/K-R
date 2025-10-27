#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 1000

int getch(void);
void ungetch(int);
int getint(int *pn);

char buf[BUFSIZE];
int bufp = 0;

int main() {
    int n, result;

    printf("Examples to try: 123 abc 456 +789 -321 12.34 xyz\n");

    while ((result = getint(&n)) != EOF) {

        if (result == 0) {
            printf("Invalid input (incomplete sign)\n");
        } else if (result == 1) {
            printf("Valid integer found = %d\n", n);
        } else {
            printf("Invalid input '%c' (not a number)\n", result);
        }
    }

    return 0;
}

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        return c;
    }
    
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF)
                ungetch(c);
            return 0;
        }
    }
    
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    
    if (c != EOF)
        ungetch(c);

    return 1;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
