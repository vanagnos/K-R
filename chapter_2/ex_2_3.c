#include <stdio.h>

int htoi(char *s);

int main() {
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    printf("Decimal value: %d\n", htoi(hex));
    return 0;
}

int htoi(char *s) {
    int value = 0;
    int digit;
    char *ptr = s;

    if (ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X'))
        ptr += 2;

    while (*ptr != '\0') {
        if (*ptr >= '0' && *ptr <= '9') {
            digit = *ptr - '0';
        } 
        else if (*ptr >= 'a' && *ptr <= 'f') {
            digit = *ptr - 'a' + 10;
        }
        else if (*ptr >= 'A' && *ptr <= 'F') {
            digit = *ptr - 'A' + 10;
        }
        else {
            break;
        }

        value = value * 16 + digit;
        ptr++;
    }

    return value;
}
