#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>

#define MAXOP 100    
#define NUMBER '0'   
#define MAXVAL 100   
#define BUFSIZE 100  

int getop(char buf[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int sp = 0;                 /* stack pointer */
double val[MAXVAL];         /* value stack */
char buf[BUFSIZE];          /* buffer for ungetch */
int bufp = 0;               /* next free position in buf */

/* Reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop()); 
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(((int) pop()) % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("%.8g\n", pop());  
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;  
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];  
    else {
        printf("error: stack empty, can't pop value\n");
        return 0.0;
    }
}

int getop(char buf[]) {
    int i, c;
    char *s = buf;
    
    while ((*s = c = getch()) == ' ' || c == '\t')  
        s++;
    *s = '\0';

    if (!isdigit(c) && c != '.')   
        return c;

    i = 0;
    
    if (isdigit(c)) {
        while (isdigit(*s++ = c))  
            c = getch();
    }
    
    if (c == '.') {    
        *s++ = c;
        c = getch();
        while (isdigit(*s++ = c))  
            c = getch();
    }

    *s = '\0';  
    
    if (c != EOF)
        ungetch(c);  

    return NUMBER;  
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
