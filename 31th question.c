#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TRACKS 5

// Function to sort the tracks in ascending order
void sortTracks(int tracks[]) {
    for (int i = 0; i < NUM_TRACKS - 1; i++) {
        for (int j = 0; j < NUM_TRACKS - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the absolute difference between two track positions
int calculateDifference(int track1, int track2) {
    return abs(track1 - track2);
}

// Function to simulate CSCAN disk scheduling algorithm and calculate average head movement
float cscanDiskScheduling(int tracks[], int numTracks, int initialPosition) {
    sortTracks(tracks);

    int start = 0;
    int end = NUM_TRACKS - 1;

    int headMovement = 0;
    int currentTrack = initialPosition;

    // Move the head from initial position to the end of the disk
    for (int i = currentTrack; i <= 100; i++) {
        int nextTrack = (i == 100) ? 0 : i + 1;
        headMovement += calculateDifference(currentTrack, nextTrack);
        currentTrack = nextTrack;
    }

    // Move the head from the beginning of the disk to the initial position
    for (int i = 0; i < initialPosition; i++) {
        int nextTrack = (i == initialPosition - 1) ? 100 : i + 1;
        headMovement += calculateDifference(currentTrack, nextTrack);
        currentTrack = nextTrack;
    }

    // Move the head to the end of the disk again
    for (int i = 0; i <= end; i++) {
        headMovement += calculateDifference(currentTrack, tracks[i]);
        currentTrack = tracks[i];
    }

    float averageHeadMovement = (float)headMovement / numTracks;
    return averageHeadMovement;
}

int main() {
    int tracks[NUM_TRACKS] = {55, 58, 60, 70, 18};
    int initialPosition = 5;

    float averageHeadMovement = cscanDiskScheduling(tracks, NUM_TRACKS, initialPosition);

    printf("Average head movement: %.2f\n", averageHeadMovement);

    return 0;
}

