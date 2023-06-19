#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_TRACKS 9

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

// Function to simulate SCAN disk scheduling algorithm and calculate average head movement
float scanDiskScheduling(int tracks[], int numTracks, int initialPosition) {
    sortTracks(tracks);

    int headMovement = 0;
    int currentTrack = initialPosition;
    int direction = 1;  // 1 for moving towards higher track numbers, -1 for moving towards lower track numbers

    // Move the head towards higher track numbers
    for (int i = initialPosition; i <= 200; i++) {
        int nextTrack = i;
        if (nextTrack > 200) {
            nextTrack = 0;
            direction = -1;
        }
        headMovement += calculateDifference(currentTrack, nextTrack);
        currentTrack = nextTrack;
    }

    // Move the head towards lower track numbers
    for (int i = currentTrack; i >= 0; i--) {
        int nextTrack = i;
        headMovement += calculateDifference(currentTrack, nextTrack);
        currentTrack = nextTrack;
    }

    float averageHeadMovement = (float)headMovement / numTracks;
    return averageHeadMovement;
}

int main() {
    int tracks[NUM_TRACKS] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int initialPosition = 100;

    float averageHeadMovement = scanDiskScheduling(tracks, NUM_TRACKS, initialPosition);

    printf("Average head movement: %.2f\n", averageHeadMovement);

    return 0;
}

