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
void peek(void);          /* New command: Print the top element without popping */
void duplicate(void);     /* New command: Duplicate the top element */
void swap(void);          /* New command: Swap the top two elements */
void clear(void);         /* New command: Clear the stack */
int getch(void);
void ungetch(int);
void setvar(char name, double value);
double getvar(char name);

/* Global variables */
int sp = 0;                 /* stack pointer */
double val[MAXVAL];         /* value stack */
char buf[BUFSIZE];          /* buffer for ungetch */
int bufp = 0;               /* next free position in buf */
double vars[26];          /* 26 variables: 'A' to 'Z' */
double recent = 0.0;      /* Most recently printed value */

/* Reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];
    int var = 0;

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
            case '=': {  /* Variable assignment */
                double value = pop();
                char name = (char)pop();
                setvar(name, value);
                push(value);
                break;
            }
            case '\n':
                printf("%.8g\n", pop());  
                break;
            case 'p':  /* Print top element */
                peek();
                break;
            case 'd':  /* Duplicate top element */
                duplicate();
                break;
            case 's':  /* Swap top two elements */
                swap();
                break;
            case 'c':  /* Clear the stack */
                clear();
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    push(getvar(type));
                    var = type;
                } else if (type == '=') {
                    double value = pop();
                    setvar(var, value);
                    push(value);
                } else if (type == 'R') {
                    push(recent);
                } else {
                    printf("error: unknown command %s\n", s);
                }
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

void peek(void) {
    if (sp > 0) {
        printf("Top element: %.8g\n", *(val + sp - 1));
    } else {
        printf("error: stack empty, can't peek\n");
    }
}



void duplicate(void) {
    if (sp > 0) {
        push(*(val + sp - 1));
    } else {
        printf("error: stack empty, can't duplicate\n");
    }
}

void swap(void) {
    if (sp > 1) {
        double *top1 = val + sp - 1;  // Pointer to the top element
        double *top2 = val + sp - 2;  // Pointer to the second element

        double temp = *top1;
        *top1 = *top2;
        *top2 = temp;
    } else {
        printf("error: not enough elements to swap\n");
    }
}

void clear(void) {
    while (sp > 0)
        val[sp--] = 0;
    printf("Stack cleared\n");
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
    
    if (isdigit(c)) {  /* Collect integer part */
        while (isdigit(*s++ = c))  
            c = getch();
    }
    
    if (c == '.') {    /* Collect fractional part */
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

void setvar(char name, double value) {
    *(vars + (name - 'A')) = value;
}

double getvar(char name) {
    return *(vars + (name - 'A'));
}
