#include <stdio.h>
#include <ctype.h>

double atof(char *s);  

/* atof: convert string s to double, extended for scientific notation */
double atof(char *s) {
    double val, power, exponent;
    int sign, exp_sign, i;
    char *ptr = s;

    
    while(isspace(*ptr))
        ptr++;

    sign = (*ptr == '-') ? -1 : 1;
    if (*ptr == '+' || *ptr == '-')  
        ptr++;

    for (val = 0.0; isdigit(*ptr); ptr++)  
        val = 10.0 * val + (*ptr - '0');

    if (*ptr == '.') {
        ptr++;
        for (power = 1.0; isdigit(*ptr); ptr++) {  
            val = 10.0 * val + (*ptr - '0');
            power *= 10;
        }
    }

    if (*ptr == 'e' || *ptr == 'E') {
        ptr++;
        exp_sign = (*ptr == '-') ? -1 : 1;  
        if (*ptr == '+' || *ptr == '-')  
            ptr++;

        for (exponent = 0.0; isdigit(*ptr); ptr++) {  
            exponent = 10.0 * exponent + (*ptr - '0');
        }
        exponent *= exp_sign;  

        while (exponent > 0) {
            val *= 10.0;
            exponent--;
        }
        while (exponent < 0) {
            val /= 10.0;
            exponent++;
        }
    }

    return sign * val / power;
}

int main() {
    char num1[] = "123.45e-6";
    char num2[] = "-0.003e+3";
    char num3[] = "123.45";
    
    printf("Converted value (num1): %f\n", atof(num1));  // Expected: 0.00012345
    printf("Converted value (num2): %f\n", atof(num2));  // Expected: -3.000000
    printf("Converted value (num3): %f\n", atof(num3));  // Expected: 123.450000
    
    return 0;
}
