//Write a program to perform the operations of the Circular linked list: Insertion.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* tail = NULL;
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail; 
    } else {
        newNode->next = tail->next; 
        tail->next = newNode; 
        tail = newNode; 
    }
}
void display() {
    if (tail == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }
    struct Node* temp = tail->next; 
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next); 
    printf("\n");
}
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    return 0;
}
