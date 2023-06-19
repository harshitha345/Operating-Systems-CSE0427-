#include <stdio.h>
#include <stdbool.h>

#define MAX_PARTITIONS 4
#define MAX_PROCESSES 5

// Structure to represent a memory partition
typedef struct {
    int size;
    bool allocated;
}memory partition;

int findWorstFitPartition(MemoryPartition partitions[], int numPartitions, int processSize) {
    int worstFitIndex = -1;
    int worstFitSize = -1;

    for (int i = 0; i < numPartitions; i++) {
        if (!partitions[i].allocated && partitions[i].size >= processSize) {
            if (worstFitIndex == -1 || partitions[i].size > worstFitSize) {
                worstFitIndex = i;
				itSize = partitions[i].size;
            }
        }
    }
 worstFitIndex;
}
void allocateMemory(MemoryPartition partitions[], int numPartitions, int processSizes[], int numProcesses) {
    for (int i = 0; i < numProcesses; i++) {
        int processSize = processSizes[i];
        int partitionIndex = findWorstFitPartition(partitions, numPartitions, processSize);

        if (partitionIndex != -1) {
            partitions[partitionIndex].allocated = true;
            printf("Process of size %d KB allocated to partition %d.\n", processSize, partitionIndex + 1);
        } else {
            printf("Process of size %d KB cannot be allocated.\n", processSize);
        }
    }
}

int main() {
    MemoryPartition partitions[MAX_PARTITIONS] = {
        {40, false},
        {10, false},
        {30, false},
        {60, false}
    };

    int processSizes[MAX_PROCESSES] = {100, 50, 30, 120, 35};

    allocateMemory(partitions, MAX_PARTITIONS, processSizes, MAX_PROCESSES);

    return 0;
}

