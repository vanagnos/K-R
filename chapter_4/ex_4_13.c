#include <stdio.h>
#include <string.h>

void reverse_rec(char *start, char *end) {
    if (start >= end)
        return;

    char temp = *start;
    *start = *end;
    *end = temp;

    reverse_rec(++start, --end);
}

void reverse(char *s) {
    int len = strlen(s);
    if (len > 1) {
        char *start = s;
        char *end = s;
        while (*end != '\0')
            end++;
        end--;
           
        reverse_rec(start, end);
    }
}

int main() {
    char str1[] = "hello";
    char str2[] = "world!";
    char str3[] = "a";
    char str4[] = "";

    reverse(str1);
    printf("%s\n", str1);  // Expected: "olleh"

    reverse(str2);
    printf("%s\n", str2);  // Expected: "!dlrow"

    reverse(str3);
    printf("%s\n", str3);  // Expected: "a"

    reverse(str4);
    printf("%s\n", str4);  // Expected: ""

    return 0;
}
