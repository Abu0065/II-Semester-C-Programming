#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("\n--- Current Patient Queue ---\n");
    int pos = 1;
    while (temp != NULL) {
        printf("%d. %s (Age: %d)\n", pos++, temp->name, temp->age);
        temp = temp->next;
    }
    printf("-----------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nClinic Management System");
        printf("\n1. Add Patient\n2. Serve Patient\n3. View Next Patient\n4. Display All Waiting\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: servePatient(); break;
            case 3: viewNext(); break;
            case 4: displayQueue(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.");
        }
    }
    return 0;
}