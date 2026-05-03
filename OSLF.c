#include <stdio.h>

void calculateWaitingTime(int processes[], int n, int bt[], int wt[]) {
    // Waiting time for the first process is always 0
    wt[0] = 0;

    // Calculate waiting time for each subsequent process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void calculateTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Turnaround time = Burst Time + Waiting Time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    calculateWaitingTime(processes, n, bt, wt);
    calculateTurnAroundTime(processes, n, bt, wt, tat);

    printf("Process ID  Burst Time  Waiting Time  Turnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("    %d\t\t%d\t\t%d\t\t%d\n", (i + 1), bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
    // Process IDs
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);

    // Burst time of all processes
    int burst_time[] = {10, 5, 8};

    findAverageTime(processes, n, burst_time);

    return 0;
}

