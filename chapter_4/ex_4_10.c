#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>

#define MAXOP 100    
#define NUMBER '0'   
#define MAXVAL 100   

int getop(char buf[]);
void push(double);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
void setvar(char name, double value);
double getvar(char name);

/* Global variables */
int sp = 0;                 
double val[MAXVAL];         
double vars[26];            
double recent = 0.0;        

char line[MAXOP];   /* Stores input line */
char *lp;           /* Pointer to current char in line */

/* Reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];
    int var = 0;

    while (fgets(line, MAXOP, stdin) != NULL) {
        lp = line;  /* Initialize pointer to start of line */

        while ((type = getop(s)) != '\0') {
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
                    recent = pop();
                    printf("%.8g\n", recent);  
                    break;
                case 'p':  
                    peek();
                    break;
                case 'd':  
                    duplicate();
                    break;
                case 's':  
                    swap();
                    break;
                case 'c':  
                    clear();
                    break;
                default:
                    if (type >= 'A' && type <= 'Z') {
                        push(getvar(type));
                        var = type;
                    } else if (type == 'R') {
                        push(recent);
                    } else {
                        printf("error: unknown command %s\n", s);
                    }
                    break;
            }
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
        /* POINTER MANIPULATION HERE */
    } else {
        printf("error: stack empty, can't peek\n");
    }
}

void duplicate(void) {
    if (sp > 0) {
        /* POINTER MANIPULATION HERE */
    } else {
        printf("error: stack empty, can't duplicate\n");
    }
}

void swap(void) {
    if (sp > 1) {
        /* POINTER MANIPULATION HERE */
    } else {
        printf("error: not enough elements to swap\n");
    }
}

void clear(void) {
    while (sp > 0)
        val[sp--] = 0;
    printf("Stack cleared\n");
}

int getop(char s[]) {
    int c;
    char *p = s;

    /* Skip whitespace */
    while ((*p = c = *lp++) == ' ' || c == '\t')
        ;

    if (c == '\0')
        return '\0';

    if (c == '\n')
        return '\n';
            
    *p++ = c;

    if (!isdigit(c) && c != '.')
        return c;

    /* Collect integer part */
    if (isdigit(c)) {
        while (isdigit(*p++ = c = *lp++))
            ;
    }

    /* Collect fractional part */
    if (c == '.') {
        while (isdigit(*p++ = c = *lp++))
            ;
    }

    *p = '\0';

    /* Unread last character if necessary */
    if (c != '\0' && !isdigit(c) && c != '.')
        lp--;

    return NUMBER;
}

void setvar(char name, double value) {
    *(vars + (name - 'A')) = value;
}

double getvar(char name) {
    return *(vars + (name - 'A'));
}
