#include <stdio.h>

void squeeze(char *s1, char *s2);

int main() {
    char str1[] = "hello world";
    char str2[] = "lod";
    squeeze(str1, str2);
    printf("%s\n", str1);  // Output: he wr
    return 0;
}

void squeeze(char *s1, char *s2) {
    char *read = s1;
    char *write = s1;

    while (*read != '\0') {
        char *p = s2;
        int match = 0;

        while (*p != '\0') {
            if (*read == *p) {
                match = 1;
                break;
            }
            p++;
        }

        if (!match) {
            *write = *read;
            write++;
        }

        read++;
    }

    *write = '\0';
}
