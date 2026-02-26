// Write a program to perform all operations: For the Stack using an Array.
#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int item) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = item;
        printf("Pushed: %d\n", item);
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
int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return -1; 
    } else {
        return stack[top];
    }
}
void display() {
    if (top < 0) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    display();
    return 0;
}
