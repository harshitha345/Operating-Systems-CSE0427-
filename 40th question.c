#include <stdio.h>
#include <stdlib.h>

void CLOOK(int tracks[], int n, int start)
{
    int head = start;
    int total_movement = 0;

    int i, j;

    // Sort the tracks in ascending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (tracks[i] > tracks[j])
            {
                int temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }

    // Find the position of the head in the sorted list
    int pos = 0;
    for (i = 0; i < n; i++)
    {
        if (tracks[i] == head)
        {
            pos = i;
            break;
        }
    }

    // Move towards higher tracks
    for (i = pos; i < n; i++)
    {
        total_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    // Move to the beginning of the disk (track 0)
    total_movement += abs(head - 0);
    head = 0;

    // Move towards higher tracks (from 0 to the position before the initial head position)
    for (i = 0; i < pos - 1; i++)
    {
        total_movement += abs(head - tracks[i]);
        head = tracks[i];
    }

    printf("Average Head Movement: %.2f\n", (float)total_movement / (float)n);
}

int main()
{
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int start = 50;

    CLOOK(tracks, n, start);

    return 0;
}
