#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTE_LENGTH 200

void displayMenu() {
    printf("\nNotes App\n");
    printf("1. Add a note\n");
    printf("2. View all notes\n");
    printf("3. Delete a note\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void addNote() {
    FILE *file = fopen("notes.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char note[MAX_NOTE_LENGTH];
    printf("Enter your note: ");
    fgets(note, MAX_NOTE_LENGTH, stdin);
    note[strcspn(note, "\n")] = '\0'; // Remove newline character

    fprintf(file, "%s\n", note);
    fclose(file);

    printf("Note added successfully.\n");
}

void viewNotes() {
    FILE *file = fopen("notes.txt", "r");
    if (file == NULL) {
        printf("No notes available.\n");
        return;
    }

    char note[MAX_NOTE_LENGTH];
    int count = 1;

    printf("Your notes:\n");
    while (fgets(note, MAX_NOTE_LENGTH, file) != NULL) {
        printf("%d. %s", count, note);
        count++;
    }

    fclose(file);
}

void deleteNote() {
    FILE *file = fopen("notes.txt", "r");
    if (file == NULL) {
        printf("No notes available to delete.\n");
        return;
    }

    char note[MAX_NOTE_LENGTH];
    int numNotes = 0;

    while (fgets(note, MAX_NOTE_LENGTH, file) != NULL) {
        numNotes++;
    }

    fclose(file);

    if (numNotes == 0) {
        printf("No notes available to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the note to delete (1-%d): ", numNotes);
    scanf("%d", &index);

    file = fopen("notes.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    int count = 1;
    while (fgets(note, MAX_NOTE_LENGTH, file) != NULL) {
        if (count != index) {
            fprintf(tempFile, "%s", note);
        }
        count++;
    }

    fclose(file);
    fclose(tempFile);

    remove("notes.txt");
    rename("temp.txt", "notes.txt");

    printf("Note deleted successfully.\n");
}

int main() {
    FILE *file = fopen("notes.txt", "a");
    if (file == NULL) {
        printf("Error creating/opening notes file.\n");
        return -1;
    }
    fclose(file);

    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addNote();
                break;
            case 2:
                viewNotes();
                break;
            case 3:
                deleteNote();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

