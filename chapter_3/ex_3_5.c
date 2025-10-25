#include <stdio.h>
#include <string.h>

void itob(int n, char *s, int b);

int main() {
    int num = 255;
    char str[50];

    itob(num, str, 16);
    printf("Base 16: %s\n", str);

    itob(num, str, 2);
    printf("Base 2: %s\n", str);

    itob(num, str, 8);
    printf("Base 8: %s\n", str);

    return 0;
}

void itob(int n, char *s, int b) {
    static const char digits[] = "0123456789ABCDEF";
    int sign;
    char *p = s;
    int rem;

    if ((sign = n) < 0)
        n = -n;

    do {
        rem = n % b;
        *p++ = digits[rem];
        n /= b;
    } while (n > 0);

    if (sign < 0)
        *p++ = '-';

    *p = '\0';

    char *start = s;
    char *end = p - 1;
    while (start < end){
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
