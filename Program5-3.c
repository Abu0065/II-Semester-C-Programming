//Write a program to perform all operations: For the Circular Queue using an Array.
#include <stdio.h>
#define MAX 100
int circularQueue[MAX];
int front = -1, rear = -1;
void enqueue(int item) {
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue overflow\n");
    } else {
        if (front == -1) front = 0; 
        rear = (rear + 1) % MAX;
        circularQueue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}
int dequeue() {
    if (front == -1) {
        printf("Circular Queue underflow\n");
        return -1;
    } else {
        int item = circularQueue[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX;
        }
        return item;
    }
}
int peek() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
        return -1;
    } else {
        return circularQueue[front];
    }
}
void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", circularQueue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Front element: %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());
    display();
    return 0;
}
