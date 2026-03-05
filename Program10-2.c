//Write a program to perform all operations: For Queue using Linked List.
#include <stdio.h>
#include <stdlib.h>
struct Patient {
    char name[50];
    int age;
    struct Patient* next;
};
struct Patient *front = NULL;
struct Patient *rear = NULL;
void addPatient() {
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    if (newPatient == NULL) {
        printf("\nMemory allocation failed!");
        return;
    }

    printf("Enter Patient Name: ");
    scanf(" %[^\n]s", newPatient->name);
    printf("Enter Patient Age: ");
    scanf("%d", &newPatient->age);
    newPatient->next = NULL;

    if (rear == NULL) {
        front = rear = newPatient;
    } else {
        rear->next = newPatient;
        rear = newPatient;
    }
    printf("Patient %s added to the queue.\n", newPatient->name);
}
void servePatient() {
    if (front == NULL) {
        printf("\nNo patients in the queue!\n");
        return;
    }

    struct Patient* temp = front;
    printf("\nServing Patient: %s (Age: %d)\n", temp->name, temp->age);
    
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}
void viewNext() {
    if (front == NULL) {
        printf("\nQueue is empty.\n");
    } else {
        printf("\nNext Patient in line: %s\n", front->name);
    }
}
void displayQueue() {
    if (front == NULL) {
        printf("\nNo patients currently waiting.\n");
        return;
    }
    struct Patient* temp = front;
    printf("\nPatients in Queue:\n");
    while (temp != NULL) {
        printf("- %s (Age: %d)\n", temp->name, temp->age);
        temp = temp->next;
    }
}
int main() {
    int choice;
    do {
        printf("\nClinic Queue Management:\n");
        printf("1. Add Patient\n");
        printf("2. Serve Patient\n");
        printf("3. View Next Patient\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                servePatient();
                break;
            case 3:
                viewNext();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}
