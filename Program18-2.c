//Design and implement a queue-based appointment management system for a clinic that handles patients in the order of their arrival. The system should maintain a First-Come, First-Served (FCFS) queue for patients and provide options to add new patients, view the next patient to be treated, serve (remove) a patient once treated, and display the list of all waiting patients. 
#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100
typedef struct {
    char name[50];
    int priority; 
} Patient;

typedef struct {
    Patient patients[MAX_PATIENTS]; 
    int front;
    int rear;
} ClinicQueue;

void initQueue(ClinicQueue *q);
int isEmpty(ClinicQueue *q);
int isFull(ClinicQueue *q);
void addPatient(ClinicQueue *q, char *name, int priority);
void servePatient(ClinicQueue *q);
void viewNextPatient(ClinicQueue *q);
void displayWaitingPatients(ClinicQueue *q);

int main() {
    ClinicQueue clinic;
    initQueue(&clinic);
    
    int choice, priority;
    char nameBuffer[50];

    do {
        printf("\n=== Priority Clinic System ===\n");
        printf("1. Add Regular Patient (Priority 2)\n");
        printf("2. Add Emergency Patient (Priority 1)\n");
        printf("3. Serve Patient\n");
        printf("4. View Next Patient\n");
        printf("5. Display Waiting List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
            case 2:
                printf("Enter patient's name: ");
                fgets(nameBuffer, sizeof(nameBuffer), stdin);
                nameBuffer[strcspn(nameBuffer, "\n")] = 0; 
                
                priority = (choice == 1) ? 2 : 1; 
                addPatient(&clinic, nameBuffer, priority);
                break;
            case 3:
                servePatient(&clinic);
                break;
            case 4:
                viewNextPatient(&clinic);
                break;
            case 5:
                displayWaitingPatients(&clinic);
                break;
            case 6:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void initQueue(ClinicQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(ClinicQueue *q) {
    return (q->front == -1 || q->front > q->rear);
}

int isFull(ClinicQueue *q) {
    return (q->rear == MAX_PATIENTS - 1);
}

void addPatient(ClinicQueue *q, char *name, int priority) {
    if (isFull(q)) {
        printf("[-] The waiting room is full!\n");
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
        strcpy(q->patients[q->rear].name, name);
        q->patients[q->rear].priority = priority;
    } else {

        int i;
        for (i = q->rear; i >= q->front; i--) {

            if (q->patients[i].priority > priority) {
                q->patients[i + 1] = q->patients[i];
            } else {
                break;
            }
        }
        strcpy(q->patients[i + 1].name, name);
        q->patients[i + 1].priority = priority;
        q->rear++;
    }
    
    char *priorityLabel = (priority == 1) ? "EMERGENCY" : "Regular";
    printf("[+] %s Patient '%s' added to the waiting list.\n", priorityLabel, name);
}

void servePatient(ClinicQueue *q) {
    if (isEmpty(q)) {
        printf("[-] No patients are currently waiting.\n");
        return;
    }
    
    printf("[✓] Served '%s' (Priority: %d).\n", q->patients[q->front].name, q->patients[q->front].priority);
    q->front++;
    
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

void viewNextPatient(ClinicQueue *q) {
    if (isEmpty(q)) {
        printf("[-] No patients are currently waiting.\n");
        return;
    }
    printf("[*] Next up: %s (Priority: %d)\n", q->patients[q->front].name, q->patients[q->front].priority);
}

void displayWaitingPatients(ClinicQueue *q) {
    if (isEmpty(q)) {
        printf("[-] The waiting room is empty.\n");
        return;
    }
    
    printf("[*] Waiting list (Ordered by Priority & Arrival):\n");
    int displayIndex = 1;
    for (int i = q->front; i <= q->rear; i++) {
        char *pLabel = (q->patients[i].priority == 1) ? "[EMERGENCY]" : "[Regular]  ";
        printf("    %d. %s %s\n", displayIndex++, pLabel, q->patients[i].name);
    }
}
