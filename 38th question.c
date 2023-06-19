#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, minm = 9999, shortest = 0, finish_time;
    int check = 0;

    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((processes[j] <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }

        if (check == 0)
        {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = 9999;

        if (rt[shortest] == 0)
        {
            complete++;
            check = 0;
            finish_time = t + 1;

            wt[shortest] = finish_time - bt[shortest] - processes[shortest];
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);

    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / (float)n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / (float)n);
}

int main()
{
    int processes[] = {0, 1, 2};
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = {2, 4, 8};

    findAverageTime(processes, n, burst_time);

    return 0;
}
