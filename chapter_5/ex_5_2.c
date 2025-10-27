#include <ctype.h>
#include <stdio.h>
#include <math.h>
#define BUFSIZE 1000

int getch(void);
void ungetch(int);
int getfloat(float *pf);

char buf[BUFSIZE];
int bufp = 0;

int main() {
    int result;
    float n;

    printf("Examples to try: 123.45 -67.89e-2 +3.14E+2 .5 2. xyz\n");

    while ((result = getfloat(&n)) != EOF) {
        if (result == 0) {
            printf("Invalid input (incomplete sign or exponent)\n");
        } else if (result == 1) {
            printf("Valid float found = %.6f\n", n);  
        } else {
            printf("Invalid input '%c' (not a number)\n", result);
        }
    }

    return 0;
}

int getfloat(float *pf) {
    int c, sign;
    float power;
    
    while (isspace(c = getch()))
        ;
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        return c;
    }
    
    sign = (c == '-') ? -1 : 1;
    
    if (c == '+' || c == '-') {
        c = getch();
        // Check if sign is followed by digit or decimal point
        if (!isdigit(c) && c != '.') {
            if (c != EOF)
                ungetch(c);
            return 0;
        }
    }
    
    *pf = 0.0;
    
    for ( ; isdigit(c); c = getch())
        *pf = 10.0 * *pf + (c - '0');
    
    if (c == '.') {
        c = getch();
        for (power = 1.0; isdigit(c); c = getch()) {
            *pf = 10.0 * *pf + (c - '0');
            power *= 10.0;
        }
        *pf = *pf / power;
    }

    *pf *= sign;
    
    if (c == 'e' || c == 'E') {
        int exp_sign = 1, exp_value = 0;
        int saved_e = c;  
        
        c = getch();
        
        if (c == '+' || c == '-') {
            exp_sign = (c == '-') ? -1 : 1;
            c = getch();
        }
            
       
        if (!isdigit(c)) {
            // Invalid exponent - push back characters in reverse order
            if (c != EOF)
                ungetch(c);
            if (exp_sign == -1)
                ungetch('-');
            else if (c == '+')
                ungetch('+');
            ungetch(saved_e);
            return 0;
        }
        
        for ( ; isdigit(c); c = getch())
            exp_value = 10 * exp_value + (c - '0');
            
        exp_value *= exp_sign;
        *pf *= pow(10.0, exp_value);
    }
    
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
