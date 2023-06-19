#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 5

// Structure to represent a memory partition
struct Partition {
    int id;
    int size;
    bool allocated;
};

// Function to allocate memory using the first-fit algorithm
void allocateMemory(struct Partition partitions[], int numPartitions, int processSize) {
    int i;
    for (i = 0; i < numPartitions; i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            partitions[i].allocated = true;
            printf("Process of size %d KB allocated to Partition %d.\n", processSize, partitions[i].id);
            break;
        }
    }

    if (i == numPartitions) {
        printf("Unable to allocate Process of size %d KB.\n", processSize);
    }
}

// Function to display the status of memory partitions
void displayMemoryStatus(struct Partition partitions[], int numPartitions) {
    printf("\nMemory Partition Status:\n");
    printf("------------------------\n");
    printf("Partition   Size (KB)   Allocated\n");
    printf("--------------------------------\n");

    for (int i = 0; i < numPartitions; i++) {
        printf("%-11d %-11d %-10s\n", partitions[i].id, partitions[i].size,
               partitions[i].allocated ? "Yes" : "No");
    }

    printf("--------------------------------\n\n");
}

int main() {
    struct Partition partitions[MAX_PARTITIONS] = {
        {1, 40, false},
        {2, 10, false},
        {3, 30, false},
        {4, 60, false}
    };

    int numPartitions = 4;

    int processSizes[] = {100, 50, 30, 120, 35};
    int numProcesses = sizeof(processSizes) / sizeof(processSizes[0]);

    // Allocate memory for each process using the first-fit algorithm
    for (int i = 0; i < numProcesses; i++) {
        displayMemoryStatus(partitions, numPartitions);
        allocateMemory(partitions, numPartitions, processSizes[i]);
    }

    return 0;
}

