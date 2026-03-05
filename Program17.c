//Create a basic system that recommends irrigation time based on soil type and crop, using linked lists to store crop data.
#include <stdio.h>
#include <stdlib.h>
struct Crop {
    char name[50];
    char soilType[50];
    int irrigationTime; 
    struct Crop* next;
};
struct Crop* head = NULL;
void addCrop() {
    struct Crop* newCrop = (struct Crop*)malloc(sizeof(struct Crop));
    if (newCrop == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter crop name: ");
    scanf("%s", newCrop->name);
    printf("Enter soil type: ");
    scanf("%s", newCrop->soilType);
    printf("Enter irrigation time (in hours): ");
    scanf("%d", &newCrop->irrigationTime);
    newCrop->next = head;
    head = newCrop;
}
void recommendIrrigationTime() {
    char soilType[50];
    printf("Enter soil type to get irrigation recommendation: ");
    scanf("%s", soilType);
    struct Crop* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->soilType, soilType) == 0) {
            printf("Crop: %s, Irrigation Time: %d hours\n", temp->name, temp->irrigationTime);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No crops found for the given soil type.\n");
    }
}
void displayCrops() {
    if (head == NULL) {
        printf("No crops available!\n");
        return;
    }
    struct Crop* temp = head;
    printf("Crops in the system:\n");
    while (temp != NULL) {
        printf("Crop: %s, Soil Type: %s, Irrigation Time: %d hours\n", temp->name, temp->soilType, temp->irrigationTime);
        temp = temp->next;
    }
}
int main() {
    int choice;
    while (1) {
        printf("\n--- Irrigation Time Recommendation System ---\n");
        printf("1. Add Crop\n");
        printf("2. Recommend Irrigation Time\n");
        printf("3. Display All Crops\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCrop();
                break;
            case 2:
                recommendIrrigationTime();
                break;
            case 3:
                displayCrops();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
