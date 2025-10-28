#include <stdio.h>

char *strncpy_custom(char *s, const char *t, int n) {
    char *start = s;

    while (*start != '\0')
        start++;

    while (n > 0 && *t != '\0') {
        *start++ = *t++;
        n--;
    }

    // if t ended early, pad remaining n characters with '\0'
    while (n > 0 && *t == '\0') {
        *start++ = '\0';
        n--;
    }

    *start = '\0';
    return start;
}

int main(void) {
    char src[] = "world!";
    char dest[14] = "Hello, ";

    strncpy_custom(dest, src, 6);

    printf("Copied string: '%s'\n", dest);
    return 0;
}

