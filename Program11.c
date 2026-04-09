//Write a program to perform concatenation of two linked lists.
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* head1 = NULL;
struct Node* head2 = NULL;
void createList(struct Node** head) {
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = value;
        newNode->next = NULL;
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}
void concatenate() {
    if (head1 == NULL) {
        head1 = head2;
    } else {
        struct Node* temp = head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty! No elements to display.\n");
        return;
    }
    struct Node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    printf("Creating first linked list:\n");
    createList(&head1);
    printf("Creating second linked list:\n");
    createList(&head2);
    printf("First linked list:\n");
    display(head1);
    printf("Second linked list:\n");
    display(head2);
    concatenate();
    printf("Concatenated linked list:\n");
    display(head1);
    return 0;
}
