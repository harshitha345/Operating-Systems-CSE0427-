#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_REFERENCES 8

// Function to check if a page is present in the frames
bool isPagePresent(int frames[], int numFrames, int page) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the optimal page to replace
int findOptimalPage(int frames[], int numFrames, int pages[], int numPages, int currentIndex) {
    int replaceIndex = -1;
    int farthestIndex = currentIndex;

    for (int i = 0; i < numFrames; i++) {
        int frame = frames[i];
        bool found = false;

        for (int j = currentIndex; j < numPages; j++) {
            if (frame == pages[j]) {
                found = true;
                if (j > farthestIndex) {
                    farthestIndex = j;
                    replaceIndex = i;
                }
                break;
            }
        }

        if (!found) {
            replaceIndex = i;
            break;
        }
    }

    return replaceIndex;
}

// Function to simulate the Optimal page replacement algorithm
int optimalPageReplacement(int frames[], int numFrames, int pages[], int numPages) {
    int pageFaults = 0;

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];

        if (!isPagePresent(frames, numFrames, page)) {
            int replaceIndex = findOptimalPage(frames, numFrames, pages, numPages, i);
            frames[replaceIndex] = page;
            pageFaults++;
        }

        printf("Page %d: ", page);
        for (int j = 0; j < numFrames; j++) {
            printf("%d ", frames[j]);
        }
        printf("\n");
    }

    return pageFaults;
}

int main() {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int pages[MAX_REFERENCES] = {4, 1, 2, 4, 3, 2, 1, 5};
    int numFrames = MAX_FRAMES;
    int numPages = MAX_REFERENCES;

    int pageFaults = optimalPageReplacement(frames, numFrames, pages, numPages);

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
    
