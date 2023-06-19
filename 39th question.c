#include <stdio.h>
#include <stdlib.h>

void LOOK(int tracks[], int n, int start)
{
    int direction = 1; // 1 for moving towards higher tracks, -1 for moving towards lower tracks
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

    // Move towards lower tracks
    for (i = pos - 1; i >= 0; i--)
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

    LOOK(tracks, n, start);

    return 0;
}
