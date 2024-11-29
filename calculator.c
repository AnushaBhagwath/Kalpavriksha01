#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int evaluate(const char *expression, int *error) {
    char ops[100];
    int topop = -1, topval = -1;
    int vals[100];

    int i = 0, length = strlen(expression);

    while (i < length) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i])) {
            int value = 0;
            while (i < length && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            vals[++topval] = value;
        }

        else if (strchr("+-*/", expression[i])) {
            while (topop >= 0 && 
                   ((ops[topop] == '*' || ops[topop] == '/') ||
                   (expression[i] != '*' && expression[i] != '/' && (ops[topop] == '+' || ops[topop] == '-')))) {
                
                char op = ops[topop--];
                if (topval < 1) {
                    *error = 1;
                    return 0;
                }
                int b = vals[topval--];
                int a = vals[topval--];
                
                if (op == '/' && b == 0) {
                    *error = 2;
                    return 0;
                }
                
                vals[++topval] = (op == '+') ? (a + b) :
                                   (op == '-') ? (a - b) :
                                   (op == '*') ? (a * b) :
                                   (a / b);
            }
            ops[++topop] = expression[i];
            i++;
        }

        else {
            *error = 3;
            return 0;
        }
    }
        i++;
    return 0; 
}

int main() {
    char expression[1000];
    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = 0;

    int error = 0;
    int ans = evaluate(expression, &error);

    if (error == 1) {
        printf("Error: Invalid expression.\n");
    } else if (error == 2) {
        printf("Error: Division by zero.\n");
    } else if (error == 3) {
        printf("Error: Invalid expression.\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}