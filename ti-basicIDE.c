#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("TI-Basic IDE Menu\n");
    printf("1. New File\n");
    printf("2. Open File\n");
    printf("3. Save File\n");
    printf("4. Run Code\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    char filename[50];

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Creating a new file...\n");
                // Code for creating a new file goes here
                break;
            case 2:
                printf("Enter filename to open: ");
                scanf("%s", filename);
                printf("Opening file: %s\n", filename);
                // Code for opening a file goes here
                break;
            case 3:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                printf("Saving file: %s\n", filename);
                // Code for saving a file goes here
                break;
            case 4:
                printf("Running code...\n");
                // Code for running Ti-Basic code goes here
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}