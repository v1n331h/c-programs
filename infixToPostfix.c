#include <stdio.h>
#include <stdlib.h>

#define MAX 50

// Stack structure for holding operands
int stack[MAX];
int top = -1;

// Function to push a value onto the stack
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Function to pop a value from the stack
int pop() {
    if (top > -1) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Function to evaluate a suffix expression
int evaluateSuffix(char* expr) {
    int i = 0;
    while (expr[i] != '\0') {
        // If the character is a digit, push it to the stack
        if (expr[i] >= '0' && expr[i] <= '9') {
            push(expr[i] - '0');  // Convert char to integer
        } else {
            // Otherwise, the character is an operator
            int operand2 = pop();
            int operand1 = pop();
            int result;

            // Perform the operation
            switch (expr[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }
            // Push the result back to the stack
            push(result);
        }
        i++;
    }
    // The final result is at the top of the stack
    return pop();
}

// Function to check if an operator has higher precedence than another
int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char stack[MAX];
    int top = -1;

    while (infix[i] != '\0') {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  // Pop the '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }

    // Pop all remaining operators in the stack
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main() {
    char suffixExpr[MAX], infixExpr[MAX], postfixExpr[MAX];

    // Input and evaluation of suffix expression
    printf("Enter a suffix expression: ");
    scanf("%s", suffixExpr);
    printf("Result of suffix expression evaluation: %d\n", evaluateSuffix(suffixExpr));

    // Input and conversion of infix expression to postfix
    printf("Enter an infix expression: ");
    scanf("%s", infixExpr);
    infixToPostfix(infixExpr, postfixExpr);
    printf("Postfix expression: %s\n", postfixExpr);

    return 0;
}