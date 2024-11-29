#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main() {
    char expression[1000];
    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = 0;

    int error = 0;
    int ans = evaluateExpression(expression, &error);

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