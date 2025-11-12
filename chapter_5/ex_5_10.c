#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int *top = stack;

void push(int value) {
    if ((top - stack) >= MAX_STACK_SIZE) {
        printf("Stack Full. Exiting...\n");
        exit(1);
    }
    *top = value;
    top++;
}

int pop() {
    if (top == stack) {
        printf("Stack Empty\n");
        return -1;
    }
    top--;
    return *top;
}

int is_number(const char *s) {
    while (*s) {
        if (!isdigit(*s) && *s != '-') {
            return 0;
        }
        s++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <RPN expression>\n", argv[0]);
        return 1;
    }


    char **arg = argv + 1;


    while (*arg != NULL) {
        char *token = *arg;

        if (is_number(token)) {
            int num = atoi(token);
            push(num);
        } 
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            int b = pop();
            int a = pop();

            int result;
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        fprintf(stderr, "Error: Division by zero\n");
                        return 1;
                    }
                    result = a / b;
                    break;
                default:
                    fprintf(stderr, "Unknown operator: %s\n", token);
                    return 1;
            }

            push(result);  
        } else {
            fprintf(stderr, "Unknown token: %s\n", token);
            return 1;
        }
        arg++;  
    }

    if (top - stack != 1) {
        fprintf(stderr, "Error: Invalid RPN expression\n");
        return 1;
    }

    printf("Result: %d\n", pop());  
    return 0;
}
