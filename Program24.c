//Case study on Improving Quality Education through Efficient Data Structures.
#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 100
typedef struct {
    char name[50];
    int age;
    char grade[10];
} Student;
void addStudent(Student StudentList[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }
    printf("Enter student name: ");
    scanf("%s", StudentList[*count].name);
    printf("Enter student age: ");
    scanf("%d", &StudentList[*count].age);
    printf("Enter student grade: ");
    scanf("%s", StudentList[*count].grade);
    (*count)++;
}
void displayStudents(Student StudentList[], int count) {
    printf("Student List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Grade: %s\n", StudentList[i].name, StudentList[i].age, StudentList[i].grade);
    }
}
int main() {
    Student StudentList[MAX_STUDENTS];
    int count = 0;
    char choice;
    do {
        addStudent(StudentList, &count);
        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    displayStudents(StudentList, count);
    return 0;
}
