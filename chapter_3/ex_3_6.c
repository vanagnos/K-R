#include <stdio.h>

void itoa_width(int n, char *s, int width);

int main() {
    char str[50];

    itoa_width(42, str, 5);
    printf("'%s'\n", str);

    itoa_width(-7, str, 4);
    printf("'%s'\n", str);

    itoa_width(12345, str, 3);
    printf("'%s'\n", str);

    return 0;
}

void itoa_width(int n, char *s, int width) {
    static const char digits[] = "0123456789";
    int sign = n;
    char *p = s;        
    char *num_start;    

    if (sign < 0)
        n = -n;

    do {
        int rem = n % 10;
        *p++ = digits[rem];
        n /= 10;
    } while (n > 0);

    if (sign < 0)
        *p++ = '-';

    int len = p - s;  

    
    int pad = 0;
    if (len < width) {
        pad = width - len;
        char *src = p - 1;
        char *dest = p + pad - 1;

        while (src >= s) {
            *dest-- = *src--;
        }

        
        char *pad_ptr = s;
        for (int i = 0; i < pad; i++)
            *pad_ptr++ = ' ';

        p += pad; 
    }

    *p = '\0';  

    
    num_start = s + pad;
    char *end = p - 1;
    while (num_start < end) {
        char tmp = *num_start;
        *num_start = *end;
        *end = tmp;
        num_start++;
        end--;
    }
}
