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
    int count = 0;

    printf("Examples to try: 123 abc 456 +789 -321 12.34 xyz\n");

    while ((result = getint(&n)) != EOF) {
        count++;

        if (result == 0) {
            printf("Input %d: Invalid input (incomplete sign)\n", count);
            continue;
        } else if (result == 1) {
            printf("Input %d: Valid integer found = %d\n", count, n);
        } else {
            printf("Input %d: Invalid input '%c' (not a number)\n", count, result);
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
            ungetch((sign == -1) ? '-' : '+');
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
