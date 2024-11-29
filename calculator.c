#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>


int evaluate(const char *expression, int *error) {
    char operators[100];
    int values[100];
    int opTop = -1, valTop = -1;

    int i = 0, len = strlen(expression);

    while (i < len) {
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        if (isdigit(expression[i])) {
            int value = 0;
            while (i < len && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            values[++valTop] = value;
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