//Create a list where students add species and their habitats, then display them grouped by pollution tolerance.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SPECIES 100
#define MAX_HABITAT_LENGTH 100
#define MAX_TOLERANCE_LENGTH 20
typedef struct {
    char name[MAX_HABITAT_LENGTH];
    char habitat[MAX_HABITAT_LENGTH];
    char tolerance[MAX_TOLERANCE_LENGTH];
} Species;
void addSpecies(Species speciesList[], int *count) {
    if (*count >= MAX_SPECIES) {
        printf("Species list is full.\n");
        return;
    }
    printf("Enter species name: ");
    scanf("%s", speciesList[*count].name);
    printf("Enter habitat: ");
    scanf("%s", speciesList[*count].habitat);
    printf("Enter pollution tolerance (High, Medium, Low): ");
    scanf("%s", speciesList[*count].tolerance);
    (*count)++;
}
void displaySpeciesByTolerance(Species speciesList[], int count) {
    printf("Species grouped by pollution tolerance:\n");
    for (int i = 0; i < count; i++) {
        printf("Tolerance: %s, Species: %s, Habitat: %s\n", speciesList[i].tolerance, speciesList[i].name, speciesList[i].habitat);
    }
}
int main() {
    Species speciesList[MAX_SPECIES];
    int count = 0;
    char choice;
    do {
        addSpecies(speciesList, &count);
        printf("Do you want to add another species? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displaySpeciesByTolerance(speciesList, count);
    return 0;
}
