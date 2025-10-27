#include <stdio.h>
#include <stdlib.h>

void mystrcat(char *, char *);

int main() {
    char h[] = "Hello, ";
    char w[] = "World!";

    mystrcat(h, w);
    printf("%s\n", h);

}

void mystrcat(char *s, char *t) {
    while(*s != '\0')
        s++;

    while(*t != '\0')
        *s++ = *t++;

    *s = '\0';

}
