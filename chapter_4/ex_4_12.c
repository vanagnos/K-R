#include <stdio.h>


char *itoa_rec(int n, char *s) {
    if (n < 0) {
        *s++ = '-';
        n = -n;
    }

    if (n / 10) {
        s = itoa_rec(n / 10, s);
    }

    *s++ = '0' + (n % 10);
    return s;
}

void itoa(int n, char *s) {
    char *p;
    p = itoa_rec(n, s);
    *p = '\0';
}

int main(){
    char buf[20];

    itoa(12345, buf);
    printf("%s\n", buf);  /* Should print: 12345 */

    itoa(-678, buf);
    printf("%s\n", buf);  /* Should print: -678 */

    itoa(0, buf);
    printf("%s\n", buf);  /* Should print: 0 */

return 0;
}


