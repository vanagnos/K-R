
#include <stdio.h>

int any(char *s1, char *s2);

int main() {
    char str1[] = "hello world";
    char str2[] = "llo";
    printf("Location: %d\n", any(str1, str2));
    return 0;
}

int any(char *s1, char *s2) {
    char *read = s1;
    int location = 0;

    while (*read != '\0') {
        char *p = s2;
        while (*p != '\0') {
            if (*read == *p) {
                return location;
            }
            p++;
        }
        read++;
        location++;
    }

    return -1;
}
