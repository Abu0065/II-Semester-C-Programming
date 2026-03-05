//Write a program to perform all operations: For Circular Queue using Linked List
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; 
    } else {
        rear->next = newNode; 
        rear = newNode; 
        rear->next = front; 
    }
    printf("Enqueued %d to the circular queue.\n", value);
}
void dequeue() {
    if (front == NULL) {
        printf("Circular queue underflow! No elements to dequeue.\n");
        return;
    }
    struct Node* temp = front;
    printf("Dequeued %d from the circular queue.\n", temp->data);
    if (front == rear) { 
        front = rear = NULL;
    } else {
        front = front->next; 
        rear->next = front; 
    }
    free(temp);
}
void peek() {
    if (front == NULL) {
        printf("Circular queue is empty! No elements to peek.\n");
        return;
    }
    printf("Front element is: %d\n", front->data);
}
void display() {
    if (front == NULL) {
        printf("Circular queue is empty! No elements to display.\n");
        return;
    }
    struct Node* temp = front;
    printf("Circular Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front); 
    printf("\n");
}
int main() {
    int choice, value;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

