#include <stdio.h>

char *strncpy_custom(char *s, const char *t, int n) {
    char *start = s;

    while (n > 0 && *t != '\0') {
        *start++ = *t++;
        n--;
    }

    // if t ended early, pad remaining n characters with '\0'
    while (n > 0 && *t == '\0') {
        *start++ = '\0';
        n--;
    }

    return start;
}
char *strncat_custom(char *s, const char *t, int n) {
    char *start = s;

    while (*start != '\0')
        start++;

    while (n > 0 && *t != '\0') {
        *start++ = *t++;
        n--;
    }

    while (n > 0 && *t == '\0') {
        *start++ = '\0';
        n--;
    }

    *start = '\0';
    return start;
}
int strncmp_custom(const char *s, const char *t, int n) {
    while (n > 0 && *s != '\0' && *t != '\0') {
        if (*s < *t){
            return (*t - *s);
        } else if (*s > *t){
            return (*s - *t);
        }

        s++;
        t++;
        n--;
    }


    return 0;
}

int main(void) {
    char src[] = "world!";
    char dest[14] = "Hello, ";

    strncpy_custom(dest, src, 2);

    printf("Copied string: %s\n", dest);

    char src1[] = "world!";
    char dest1[14] = "Hello, ";
    strncat_custom(dest1, src1, 6);
    printf("concatenated string: %s\n", dest1);

    const char *a = "hello";
    const char *b = "helium";
    int result;

    result = strncmp_custom(a, b, 3);
    printf("Result for first 3 chars: %d\n", result);

    result = strncmp_custom(a, b, 5);
    printf("Result for first 5 chars: %d\n", result);

    return 0;
}

