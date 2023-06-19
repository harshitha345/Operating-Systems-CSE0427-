#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the absolute difference between two numbers
int absoluteDifference(int a, int b) {
    return abs(a - b);
}

// Function to find the index of the track with the shortest seek time
int findShortestSeekTime(int tracks[], int numTracks, int headPosition) {
    int shortestSeekTime = -1;
    int shortestSeekTimeIndex = -1;

    for (int i = 0; i < numTracks; i++) {
        if (tracks[i] != -1) {
            int seekTime = absoluteDifference(tracks[i], headPosition);

            if (shortestSeekTime == -1 || seekTime < shortestSeekTime) {
                shortestSeekTime = seekTime;
                shortestSeekTimeIndex = i;
            }
        }
    }

    return shortestSeekTimeIndex;
}

// Function to simulate the SSTF disk scheduling algorithm
int sstfDiskScheduling(int tracks[], int numTracks, int headPosition) {
    int totalHeadMovement = 0;
    int currentTrack = headPosition;

    printf("Sequence of tracks visited: ");

    for (int i = 0; i < numTracks; i++) {
        int shortestSeekTimeIndex = findShortestSeekTime(tracks, numTracks, currentTrack);
        int nextTrack = tracks[shortestSeekTimeIndex];

        printf("%d ", nextTrack);

        totalHeadMovement += absoluteDifference(currentTrack, nextTrack);
        currentTrack = nextTrack;
        tracks[shortestSeekTimeIndex] = -1;
    }

    printf("\n");

    return totalHeadMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);
    int headPosition = 50;

    int totalHeadMovement = sstfDiskScheduling(tracks, numTracks, headPosition);

    printf("Average head movement: %.2f\n", (float) totalHeadMovement / numTracks);

    return 0;
}
