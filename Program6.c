//Write a program to evaluate the Postfix Notation.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
    }
}
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9') {
            push(ch - '0'); 
        } else if (isOperator(ch)) {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop(); 
}
int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    fgets(expression, MAX, stdin);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
