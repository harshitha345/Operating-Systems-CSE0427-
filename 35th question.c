include <stdio.h>
#include <stdbool.h>

#define DISK_SIZE 16
#define INODE_BLOCKS 8
#define MIN_FILE_SIZE 1

// Function to allocate blocks sequentially for a file
void allocateBlocks(int disk[], int startBlock, int numBlocks) {
    printf("Allocating blocks: ");

    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        disk[i] = 1;
        printf("%d ", i);
    }

    printf("\n");
}

// Function to check if the specified blocks are free
bool areBlocksFree(int disk[], int startBlock, int numBlocks) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (disk[i] != 0) {
            return false;
        }
    }

    return true;
}

// Function to find the next available contiguous blocks
int findNextContiguousBlocks(int disk[], int startBlock, int numBlocks) {
    int contiguousBlocks = 0;

    for (int i = startBlock; i < DISK_SIZE; i++) {
        if (disk[i] == 0) {
            contiguousBlocks++;

            if (contiguousBlocks == numBlocks) {
                return i - numBlocks + 1;
            }
        } else {
            contiguousBlocks = 0;
        }
    }

    return -1;
}

// Function to allocate blocks for a file in the file system
void allocateFile(int disk[], int fileSize) {
    int numBlocks = fileSize;
    int startBlock = findNextContiguousBlocks(disk, INODE_BLOCKS, numBlocks);

    if (startBlock != -1) {
        allocateBlocks(disk, startBlock, numBlocks);
    } else {
        printf("No contiguous blocks of size %d KB are available.\n", fileSize);
    }
}

int main() {
    int disk[DISK_SIZE] = {0};

    allocateFile(disk, 4);  // Allocate a file of size 4 KB
    allocateFile(disk, 3);  // Allocate a file of size 3 KB
    allocateFile(disk, 10); // Allocate a file of size 10 KB

    return 0;
}

