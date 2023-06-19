#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 100

int main() {
    int fileDescriptor;
    char fileName[100], data[MAX_SIZE];

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", fileName);

    // Create a new file using system call
    fileDescriptor = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fileDescriptor == -1) {
        printf("Failed to create the file.\n");
        exit(1);
    }

    // Get the data from the user
    printf("Enter data to write to the file (max %d characters):\n", MAX_SIZE);
    fflush(stdin);
    fgets(data, MAX_SIZE, stdin);

    // Write the data to the file
    if (write(fileDescriptor, data, strlen(data)) == -1) {
        printf("Failed to write to the file.\n");
        close(fileDescriptor);
        exit(1);
    }

    printf("Data written to the file successfully.\n");

    // Close the file
    close(fileDescriptor);

    // Reopen the file for reading
    fileDescriptor = open(fileName, O_RDONLY);
    if (fileDescriptor == -1) {
        printf("Failed to open the file for reading.\n");
        exit(1);
    }

    // Read the data from the file
    printf("\nReading data from the file:\n");
    ssize_t bytesRead;
    char buffer[MAX_SIZE];
    while ((bytesRead = read(fileDescriptor, buffer, MAX_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    // Close the file
    close(fileDescriptor);

    return 0;
}

