#include <stdio.h>

void check_syntax(char *line);

int main() {
    char input[1000];
    while (fgets(input, sizeof(input), stdin) != NULL) {
        check_syntax(input);
    }
    return 0;
}

void check_syntax(char *line) {
    int parentheses = 0;
    int brackets = 0;
    int braces = 0;
    int in_single_quote = 0;
    int in_double_quote = 0;
    int in_single_line_comment = 0;
    int in_multi_line_comment = 0;

    char *ptr = line;

    while (*ptr != '\0') {

        if (!in_single_quote && !in_double_quote && !in_single_line_comment && !in_multi_line_comment) {

            if (*ptr == '/' && *(ptr + 1) == '/') {
                in_single_line_comment = 1;
                ptr += 2;
                continue;
            }

            else if (*ptr == '/' && *(ptr + 1) == '*') {
                in_multi_line_comment = 1;
                ptr += 2;
                continue;
            }

            else if (*ptr == '(') parentheses++;
            else if (*ptr == ')') parentheses--;
            else if (*ptr == '[') brackets++;
            else if (*ptr == ']') brackets--;
            else if (*ptr == '{') braces++;
            else if (*ptr == '}') braces--;

            else if (*ptr == '"') in_double_quote = 1;
            else if (*ptr == '\'') in_single_quote = 1;
        }

        else if (in_single_quote) {
            if (*ptr == '\\') {
                ptr++;
            } else if (*ptr == '\'') {
                in_single_quote = 0;
            }
        }

        else if (in_double_quote) {
            if (*ptr == '\\') {
                ptr++;
            } else if (*ptr == '"') {
                in_double_quote = 0;
            }
        }

        else if (in_single_line_comment) {
            if (*ptr == '\n') {
                in_single_line_comment = 0;
            }
        }

        else if (in_multi_line_comment) {
            if (*ptr == '*' && *(ptr + 1) == '/') {
                in_multi_line_comment = 0;
                ptr += 2;
                continue;
            }
        }

        ptr++;
    }

    if (parentheses != 0) printf("Unbalanced parentheses\n");
    if (brackets != 0) printf("Unbalanced brackets\n");
    if (braces != 0) printf("Unbalanced braces\n");
    if (in_single_quote) printf("Unclosed single quote\n");
    if (in_double_quote) printf("Unclosed double quote\n");
    if (in_multi_line_comment) printf("Unclosed comment\n");
}
