//System to track and visualise personal health metrics (e.g., step count, calories burned, sleep).
#include <stdio.h>
#include <stdlib.h>
#define MAX_ENTRIES 100
typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    int calories;
    float sleepHours;
} HealthEntry;
void addHealthEntry(HealthEntry healthData[], int *count) {
    if (*count >= MAX_ENTRIES) {
        printf("Health data list is full.\n");
        return;
    }
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", healthData[*count].date);
    printf("Enter step count: ");
    scanf("%d", &healthData[*count].steps);
    printf("Enter calories burned: ");
    scanf("%d", &healthData[*count].calories);
    printf("Enter sleep hours: ");
    scanf("%f", &healthData[*count].sleepHours);
    (*count)++;
}
void displayHealthData(HealthEntry healthData[], int count) {
    printf("Date       | Steps | Calories | Sleep Hours\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s | %5d | %8d | %11.2f\n", healthData[i].date, healthData[i].steps, healthData[i].calories, healthData[i].sleepHours);
    }
}
int main() {
    HealthEntry healthData[MAX_ENTRIES];
    int count = 0;
    char choice;
    do {
        addHealthEntry(healthData, &count);
        printf("Do you want to add another entry? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displayHealthData(healthData, count);
    return 0;
}
