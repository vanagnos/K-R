#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char *, char *);

int main() {
    char h[] = "Hello, ";
    char w[] = "llo, ";

    printf("%d\n", strend(h,w));

}

int strend(char *s, char *t) {
    int ret = 1;
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    if (len_t > len_s)
        return 0;

    s += len_s - len_t;

    while(*t != '\0') {
        if(*s != *t){
            return 0;
        }
        s++;
        t++;
    }

    return 1;
}
