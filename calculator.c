#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Error codes
#define ERROR_INVALID_EXPRESSION 1
#define ERROR_DIVISION_BY_ZERO 2
#define ERROR_UNKNOWN 3

#define MAX_STACK_SIZE 100

// Helper function to calculate string length
int string_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Helper function to apply an operator
int apply_operator(char operator, int a, int b, int *error) {
    if (operator == '/' && b == 0) {
        *error = ERROR_DIVISION_BY_ZERO;
        return 0;
    }
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default:
            *error = ERROR_UNKNOWN;
            return 0;
    }
}

// Helper function to check operator precedence
int operator_precedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}

// Evaluate the expression
int evaluate_expression(const char *expression, int *error) {
    char operators[MAX_STACK_SIZE];
    int operands[MAX_STACK_SIZE];
    int operator_top = -1, operand_top = -1;

    int i = 0, length = string_length(expression);

    while (i < length) {
        // Skip spaces
        if (isspace(expression[i])) {
            i++;
            continue;
        }

        // Process numbers
        if (isdigit(expression[i])) {
            int value = 0;
            while (i < length && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            if (operand_top >= MAX_STACK_SIZE - 1) {
                *error = ERROR_INVALID_EXPRESSION;
                return 0;
            }
            operands[++operand_top] = value;
        }
        // Process operators
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (operator_top >= 0 && 
                   operator_precedence(operators[operator_top]) >= operator_precedence(expression[i])) {
                if (operand_top < 1) {
                    *error = ERROR_INVALID_EXPRESSION;
                    return 0;
                }
                char op = operators[operator_top--];
                int b = operands[operand_top--];
                int a = operands[operand_top--];
                operands[++operand_top] = apply_operator(op, a, b, error);
                if (*error) return 0;
            }
            operators[++operator_top] = expression[i];
            i++;
        }
        // Invalid character
        else {
            *error = ERROR_INVALID_EXPRESSION;
            return 0;
        }
    }

    // Process remaining operators
    while (operator_top >= 0) {
        if (operand_top < 1) {
            *error = ERROR_INVALID_EXPRESSION;
            return 0;
        }
        char op = operators[operator_top--];
        int b = operands[operand_top--];
        int a = operands[operand_top--];
        operands[++operand_top] = apply_operator(op, a, b, error);
        if (*error) return 0;
    }

    return operands[operand_top];
}

// Main function
int main() {
    char expression[1000];
    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '\n') {
            expression[i] = '\0';
            break;
        }
    }

    int error = 0;
    int result = evaluate_expression(expression, &error);

    if (error == ERROR_INVALID_EXPRESSION) {
        printf("Error: Invalid expression.\n");
    } else if (error == ERROR_DIVISION_BY_ZERO) {
        printf("Error: Division by zero.\n");
    } else if (error == ERROR_UNKNOWN) {
        printf("Error: Unknown error.\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
