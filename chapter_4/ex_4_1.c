#include <stdio.h>

int strindex(char *s, char *t);

int main() {
    char s[] = "hello world, hello universe";
    char t[] = "e";

    int pos = strindex(s, t);
    printf("Rightmost occurrence of '%s' in '%s' is at index %d\n", t, s, pos);

    return 0;
}

int strindex(char *s, char *t) {
    char *s_ptr = s;
    char *t_ptr;
    char *last = NULL;

    while (*s_ptr != '\0') {
        t_ptr = t;
        char *current = s_ptr;
        while (*current != '\0' && *s_ptr != '\0' && *current == *t_ptr ) {
            current++;
            t_ptr++;
        }
        if (*t_ptr == '\0'){
           last = s_ptr;
        }
        s_ptr++;
      }

    if (last != NULL) {
        int index = last - s + 1;
        return index;
    } else {
        return -1;
    }
}
