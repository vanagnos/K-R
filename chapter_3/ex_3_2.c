#include <stdio.h>

void escape(char *s, char *t);
void unescape(char *s, char *t);

int main() {
    char input[] = "Hello\tWorld\nThis is a test!";
    char escaped[200];
    char unescaped[200];

    escape(escaped, input);
    printf("Escaped: %s\n", escaped);

    unescape(unescaped, escaped);
    printf("Unescaped: %s\n", unescaped);

    return 0;
}

void escape(char *s, char *t) {
    while (*t != '\0') {
        switch (*t) {
            case '\n':
                *s++ = '\\';
                *s++ = 'n';
                break;
            case '\t':
                *s++ = '\\';
                *s++ = 't';
                break;
            case '\b':
                *s++ = '\\';
                *s++ = 'b';
                break;
            case '\r':
                *s++ = '\\';
                *s++ = 'r';
                break;
            case '\f':
                *s++ = '\\';
                *s++ = 'f';
                break;
            case '\v':
                *s++ = '\\';
                *s++ = 'v';
                break;
            case '\\':
                *s++ = '\\';
                *s++ = '\\';
                break;
            default:
                *s++ = *t;
                break;
        }
        t++;
    }
    *s = '\0';
}

void unescape(char *s, char *t) {
    while (*t != '\0') {
        if (*t == '\\') {
            t++;
            switch (*t) {
                case 'n': *s++ = '\n'; break;
                case 't': *s++ = '\t'; break;
                case 'b': *s++ = '\b'; break;
                case 'r': *s++ = '\r'; break;
                case 'f': *s++ = '\f'; break;
                case 'v': *s++ = '\v'; break;
                case '\\': *s++ = '\\'; break;
                default: *s++ = *t; break;
            }
            t++;
        } else {
            *s++ = *t++;
        }
    }
    *s = '\0';
}
