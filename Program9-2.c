//Write a program to perform the operations of the Circular linked list: Deletion. 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->data != key) {
        if (temp->next == head) {
            printf("Node not found.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == head) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    insert(10);
    insert(20);
    insert(30);
    printf("Circular Linked List: ");
    display();
    deleteNode(20);
    printf("After deletion of 20: ");
    display();
    return 0;
}
