#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Error Codes
#define ERR_FILE_NOT_FOUND  1
#define ERR_FILE_PERMISSION 2
#define ERR_INVALID_INPUT   3
#define ERR_EXECUTION_FAIL  4

void handleFileError(int errorCode, const char *filename) {
    switch (errorCode) {
        case ERR_FILE_NOT_FOUND:
            fprintf(stderr, "Error: File '%s' not found.\n", filename);
            break;
        case ERR_FILE_PERMISSION:
            fprintf(stderr, "Error: Permission denied for file '%s'.\n", filename);
            break;
        default:
            fprintf(stderr, "Error: Unknown file error for file '%s'.\n", filename);
    }
}

void handleExecutionError(int errorCode) {
    switch (errorCode) {
        case ERR_EXECUTION_FAIL:
            fprintf(stderr, "Error: Failed to execute Ti-Basic code.\n");
            break;
        default:
            fprintf(stderr, "Error: Unknown execution error.\n");
    }
}

int main() {
    // Example usage of error handling functions
    
    // Simulate file error
    const char *filename = "nonexistent_file.txt";
    int fileErrorCode = ERR_FILE_NOT_FOUND;
    handleFileError(fileErrorCode, filename);
    
    // Simulate execution error
    int executionErrorCode = ERR_EXECUTION_FAIL;
    handleExecutionError(executionErrorCode);
    
    // Simulate invalid input error
    char userInput[50];
    printf("Enter a number: ");
    scanf("%s", userInput);
    if (!isdigit(userInput[0])) {
        fprintf(stderr, "Error: Invalid input. Please enter a number.\n");
    }

    return 0;
}