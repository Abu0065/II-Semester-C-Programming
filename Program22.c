//Design a system that organises and preserves Vedic texts in digital form, ensuring easy access to verses, rituals, and philosophical content for future generations.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERSES 100
typedef struct {
    char verse[256];
    char ritual[256];
    char philosophy[256];
} VedicText;
void addVedicText(VedicText vedicTexts[], int *count) {
    if (*count >= MAX_VERSES) {
        printf("Vedic text list is full.\n");
        return;
    }
    printf("Enter verse: ");
    scanf(" %[^\n]", vedicTexts[*count].verse);
    printf("Enter ritual: ");
    scanf(" %[^\n]", vedicTexts[*count].ritual);
    printf("Enter philosophy: ");
    scanf(" %[^\n]", vedicTexts[*count].philosophy);
    (*count)++;
}
void displayVedicTexts(VedicText vedicTexts[], int count) {
    printf("Vedic Texts:\n");
    for (int i = 0; i < count; i++) {
        printf("Verse: %s\nRitual: %s\nPhilosophy: %s\n\n", vedicTexts[i].verse, vedicTexts[i].ritual, vedicTexts[i].philosophy);
    }
}
int main() {
    VedicText vedicTexts[MAX_VERSES];
    int count = 0;
    char choice;
    do {
        addVedicText(vedicTexts, &count);
        printf("Do you want to add another Vedic text? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displayVedicTexts(vedicTexts, count);
    return 0;
}
