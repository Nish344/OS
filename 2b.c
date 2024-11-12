#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, j, n, temp;
    float wtavg, tatavg;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for(i = 0; i < n; i++) {
        p[i] = i; // Store process numbers
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    // Sort processes by burst time using selection sort for simplicity
    // This is to implement Shortest Job First (SJF) scheduling algorithm
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process number to keep track of original process IDs
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Initialize waiting time and turnaround time for the first process
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = bt[0];

    // Calculate waiting time and turnaround time for each process
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time for current process
        tat[i] = tat[i - 1] + bt[i];   // Turnaround time for current process
        wtavg += wt[i];                // Sum of waiting times
        tatavg += tat[i];              // Sum of turnaround times
    }

    // Display process details
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display average waiting and turnaround times
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
