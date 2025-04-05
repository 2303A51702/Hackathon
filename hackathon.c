#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define structure for faculty
typedef struct {
    char name[100];
    char empCode[20];
    char researchPublications[500];
    char events[300];
    char seminars[300];
    char projects[300];
    char lectures[300];
} Faculty;

// Array to store multiple entries
Faculty facultyList[MAX];
int count = 0;

// Function to add faculty data
void addFaculty() {
    if (count >= MAX) {
        printf("Database is full!\n");
        return;
    }

    Faculty f;

    printf("Enter Name: ");
    getchar(); // clear newline
    fgets(f.name, sizeof(f.name), stdin);
    f.name[strcspn(f.name, "\n")] = 0;

    printf("Enter Employee Code: ");
    fgets(f.empCode, sizeof(f.empCode), stdin);
    f.empCode[strcspn(f.empCode, "\n")] = 0;

    printf("Enter Research Publications: ");
    fgets(f.researchPublications, sizeof(f.researchPublications), stdin);
    f.researchPublications[strcspn(f.researchPublications, "\n")] = 0;

    printf("Enter Events Participated: ");
    fgets(f.events, sizeof(f.events), stdin);
    f.events[strcspn(f.events, "\n")] = 0;

    printf("Enter Seminars Attended: ");
    fgets(f.seminars, sizeof(f.seminars), stdin);
    f.seminars[strcspn(f.seminars, "\n")] = 0;

    printf("Enter Projects Done: ");
    fgets(f.projects, sizeof(f.projects), stdin);
    f.projects[strcspn(f.projects, "\n")] = 0;

    printf("Enter Lectures Delivered: ");
    fgets(f.lectures, sizeof(f.lectures), stdin);
    f.lectures[strcspn(f.lectures, "\n")] = 0;

    facultyList[count++] = f;
    printf("\nFaculty appraisal data added successfully!\n");
}

// Function to display all faculty data
void displayFaculty() {
    if (count == 0) {
        printf("No faculty data found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        Faculty f = facultyList[i];
        printf("\n--- Faculty %d ---\n", i + 1);
        printf("Name: %s\n", f.name);
        printf("Employee Code: %s\n", f.empCode);
        printf("Research Publications: %s\n", f.researchPublications);
        printf("Events: %s\n", f.events);
        printf("Seminars: %s\n", f.seminars);
        printf("Projects: %s\n", f.projects);
        printf("Lectures: %s\n", f.lectures);
    }
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n--- Faculty Self-Appraisal System (Console Version) ---\n");
        printf("1. Add Faculty Appraisal\n");
        printf("2. View All Faculty Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addFaculty(); break;
            case 2: displayFaculty(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
