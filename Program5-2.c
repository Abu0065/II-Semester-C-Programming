//Write a program to perform all operations: For the Queue using an Array.
#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int item) {
    if (rear >= MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) front = 0; 
        queue[++rear] = item;
        printf("Enqueued: %d\n", item);
    }
}
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    } else {
        return queue[front++];
    }
}
int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1; 
    } else {
        return queue[front];
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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
