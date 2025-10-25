#include <stdio.h>
#include <ctype.h>

void expand(char *s1, char *s2);

int main() {
    char s1[] = "a-d0-3-xZ";
    char s2[200];
    expand(s1, s2);
    printf("%s\n", s2);
    return 0;
}

void expand(char *s1, char *s2) {
    char c;
    char *p1 = s1;
    char *p2 = s2;

    while (*p1 != '\0') {
        if (*p1 == '-' && p1 > s1 && *(p1+1) != '\0') {
            char start = *(p1-1);
            char end = *(p1+1);

            if ((isdigit(start) && isdigit(end)) || 
                (isalpha(start) && isalpha(end))) {
                for (c = start + 1; c <= end; c++) {
                    *p2++ = c;
                }
                p1+=2;
            } else {
                *p2++ = *p1++;
            }
        } else {
            *p2++ = *p1++;
        }
    }
    *p2 = '\0';
}

