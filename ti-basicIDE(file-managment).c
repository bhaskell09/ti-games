#include <stdio.h>
#include <stdlib.h>

void createNewFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        printf("New file created: %s\n", filename);
        fclose(file);
    } else {
        printf("Failed to create the file.\n");
    }
}

void openFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        printf("File opened successfully: %s\n", filename);
        // Read and process file content here
        fclose(file);
    } else {
        printf("Failed to open the file.\n");
    }
}

void saveToFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%s", content);
        printf("File saved successfully: %s\n", filename);
        fclose(file);
    } else {
        printf("Failed to save the file.\n");
    }
}

int main() {
    char filename[50];
    char content[1000];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter content: ");
    scanf(" %[^\n]s", content); // Read content until a newline character

    createNewFile(filename);
    saveToFile(filename, content);
    openFile(filename);

    return 0;
}